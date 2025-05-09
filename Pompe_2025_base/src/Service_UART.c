#include <Service_UART.h>
#include <Service_GPIO.h>
#include "stm32f7xx_hal.h"
#include "Machine_Etat.h"
#include <Ecran_Lancer_Capteur.h>

UART_HandleTypeDef huart6;

uint8_t data_in;
uint8_t data_buffer[BUFFER_SIZE];
uint32_t counter;

uint8_t n_boitier;
uint8_t type_data;
uint16_t data;

extern uint16_t seuil_capteur_high;
extern uint16_t seuil_capteur_low;
extern int capteur_active;

uint8_t seuil_high;



void USART6_IRQHandler(void) {
    HAL_UART_IRQHandler(&huart6);
}


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
		counter = 1; // à refaire
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



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{


	if (counter < BUFFER_SIZE - 1)
	{
		data_buffer[counter] = data_in;
	}

	counter++;

	HAL_UART_Receive_IT(&huart6, &data_in, 1);
}


// this entails that there is no other reception in between each 3 bytes.
void Verif_UART()
{
	if (counter >= 2)
	{

		n_boitier = data_buffer[0] >> 4;
		type_data = (data_buffer[0] & 0xF);
		data = (data_buffer[1] << 8) + (data_buffer[2]);

		if (type_data == TOGGLE_PRISE)
		{
			if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7))
			{
				Eteint_Prise();
				Transmit_Ack(n_boitier, 1, 1);
			} else
			{
				Allume_Prise();
				Transmit_Ack(n_boitier, 1, 1);
			}
		}
		/*
		 * Zone 1 = Allumer Pompe
		 * Zone 2 = Pas de changement
		 * Zone 3 = Ne pas allumer la pompe
		 */
		else if (type_data == DATA_HUMIDITY && capteur_active == 1)
		{
			if (data < seuil_capteur_low)
			{
				seuil_high = 1;
			}
			else if (data > seuil_capteur_high)
			{
				seuil_high = 0;
			}
		}
		counter = 0;
	}
}




