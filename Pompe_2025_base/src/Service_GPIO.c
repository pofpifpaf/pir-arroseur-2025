#include <Service_GPIO.h>
#include "stm32f7xx_hal.h"
#include <Machine_Etat.h>

extern char Transi_1to0;
extern char Transi_2to0;

extern char Start_Button_Pushed;
GPIO_InitTypeDef GPIO_InitStruct = {0};


void Init_GPIO(void)
{



	// Activation des horloges

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();


	// LED B4 (STM32) et D3(Nucléo)


	GPIO_InitStruct.Pin=GPIO_PIN_4;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);



	// POMPE  G7(STM32) et D4(Nucléo)



	GPIO_InitStruct.Pin=GPIO_PIN_7;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOG,&GPIO_InitStruct);



	// UART RX PC7
	// UART TX PC6

	GPIO_InitStruct.Pin=GPIO_PIN_7;
	GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Alternate=GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin=GPIO_PIN_6;
	GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull=GPIO_PULLUP;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Alternate=GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);




	// Bouton poussoir G6 (STM32) et D2(Nucléo)


//			GPIO_InitStruct.Pin=GPIO_PIN_6;
//			GPIO_InitStruct.Mode=GPIO_MODE_INPUT;
//			GPIO_InitStruct.Pull=GPIO_PULLDOWN;
//			HAL_GPIO_Init(GPIOG,&GPIO_InitStruct);
//


	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);




	// Voir utilité
	// I2C1 GPIO Configuration
	//	    PB8     ------> I2C1_SCL
	//	    PB9     ------> I2C1_SDA
	GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


}



// Interruption du bouton poussoir
void EXTI9_5_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_6);
	Start_Button_Pushed = 1;
}




// A renommer
void Allume_Prise()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, 1);
}




// A renommer
void Eteint_Prise()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, 0);
}
