#include <Service_UART.h>
#include <Service_GPIO.h>
#include "stm32f7xx_hal.h"

#define BUFFER_SIZE 100

void USART6_IRQHandler(void) {
    HAL_UART_IRQHandler(&huart6);
}

UART_HandleTypeDef huart6;

uint8_t data_in;
uint8_t data_buffer[BUFFER_SIZE];
uint32_t counter;

char receive_toggle;

void Init_UART()
{
	__HAL_RCC_USART6_CLK_ENABLE();

	__HAL_UART_ENABLE_IT(&huart6, UART_IT_RXNE);

	HAL_NVIC_SetPriority(USART6_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(USART6_IRQn);

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
		counter = 1;
	}

	HAL_UART_Receive_IT(&huart6, &data_in, 1);

	counter = 0;

	receive_toggle = 0;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	counter++;
	if (counter < BUFFER_SIZE - 1)
	{
		data_buffer[counter] = data_in;
	}

	HAL_UART_Receive_IT(&huart6, &data_in, 1);
}

void Verif_UART()
{
	if (counter >= 2)
	{
		uint8_t n_boitier = data_buffer[0] >> 4;
		uint8_t type_data = (data_buffer[0] & 0xF);
		uint16_t data = (data_buffer[1] << 8) + (data_buffer[2]);

		if (type_data == TOGGLE_PRISE)
		{
			receive_toggle = 1;
			if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7))
			{
				Eteint_Prise();
			} else
			{
				Allume_Prise();
			}
			// Essayer d'afficher un message sur l'écran
		}
	}
}




