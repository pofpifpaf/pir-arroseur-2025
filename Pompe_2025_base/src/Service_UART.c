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

extern uint16_t seuil_capteur;
extern int capteur_active;



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
	huart6.Init.Mode = UART_MODE_RX;
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



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{


	if (counter < BUFFER_SIZE - 1)
	{
		data_buffer[counter] = data_in;
	}

	counter++;

	HAL_UART_Receive_IT(&huart6, &data_in, 1);
}



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
			} else
			{
				Allume_Prise();
			}
		}
		else if (type_data == DATA_HUMIDITY && capteur_active == 1)
		{
			// hystérésis à faire
			if (data > seuil_capteur)
			{
				Eteint_Prise();
			}
			else
			{
				Allume_Prise();
			}
		}
		counter = 0;
	}
}




