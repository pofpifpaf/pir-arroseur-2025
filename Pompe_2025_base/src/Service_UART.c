#include <Service_UART.h>
#include <Service_GPIO.h>
#include "stm32f7xx_hal.h"
#include "Machine_Etat.h"
#include <Ecran_Lancer_Capteur.h>

#include <Globals.h>

UART_HandleTypeDef huart6;

uint8_t data_buffer[BUFFER_SIZE];

uint8_t data_in;
uint8_t n_boitier;
uint8_t type_data;
uint16_t data;

uint32_t counter;

extern uint8_t zone;
extern uint16_t seuil_capteur_high;
extern uint16_t seuil_capteur_low;
extern int capteur_active;

extern int Etat;


void USART6_IRQHandler(void) {
    HAL_UART_IRQHandler(&huart6);
}

/******************************************************************/
/*                         UART Init                              */
/******************************************************************/
void Init_UART()
{
	__HAL_RCC_USART6_CLK_ENABLE();

	huart6.Instance = USART6;
	huart6.Init.BaudRate = 9600;
	huart6.Init.WordLength = UART_WORDLENGTH_8B;
	huart6.Init.StopBits = UART_STOPBITS_1;
	huart6.Init.Parity = UART_PARITY_NONE;
	huart6.Init.Mode = UART_MODE_TX_RX;
	huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart6.Init.OverSampling = UART_OVERSAMPLING_16;

	if (HAL_UART_Init(&huart6) != HAL_OK)
	{
		//Error_Handler();
	}

	__HAL_UART_ENABLE_IT(&huart6, UART_IT_RXNE);

	HAL_NVIC_SetPriority(USART6_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(USART6_IRQn);

	HAL_UART_Receive_IT(&huart6, &data_in, 1);

	counter = 0;
}

void Transmit_Ack(uint8_t n_capt, uint8_t type_data, uint8_t ack)
{
	uint8_t data = 0;

	data = (n_capt << 4) + (type_data << 1) + ack;

	HAL_UART_Transmit(&huart6, &data, sizeof(data), 50);
}

/******************************************************************/
/*                        UART Interruption                       */
/******************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (counter < BUFFER_SIZE - 1)
	{
		data_buffer[counter] = data_in;
	}

	counter++;

	HAL_UART_Receive_IT(&huart6, &data_in, 1);
}

/******************************************************************/
/*                     UART Periodic Updates                      */
/******************************************************************/
//
// Missing edge case if interruption while Verif_UART();
//
void UART_Reception_Collection()
{
	if (counter >= 2) //We wait for 3 transmissions
	{
		//Formatting incoming data
		n_boitier = data_buffer[0] >> 4;
		type_data = (data_buffer[0] & 0xF);
		data = (data_buffer[1] << 8) + (data_buffer[2]);

		if (type_data == TOGGLE_PRISE)
		{
			Toggle_Outlet();
			received_toggle_prise = 1;
			Transmit_Ack(n_boitier, 1, 1);
		}

		/*
		 * Zone 1 = Turn Outlet On
		 * Zone 2 = No change
		 * Zone 3 = Keep Outlet from turning on
		 */
		else if (type_data == DATA_HUMIDITY && capteur_active)
		{
			zone = 2;

			if (data < seuil_capteur_low) zone = 0;

			else if (data > seuil_capteur_high) zone = 1;
		}

		// Resetting the counter
		counter = 0;
	}
}




