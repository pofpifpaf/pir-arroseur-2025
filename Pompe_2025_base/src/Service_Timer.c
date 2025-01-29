/*
 * Service_Timer.c
 *
 *  Created on: 15 juil. 2021
 *      Author: mahout
 */

#include "stm32f7xx_hal.h"
#include "Machine_Etat.h"

TIM_HandleTypeDef TimHandle;


extern char Fin_Tempo;
extern int Compteur_Marche_Pompe;
extern char Minute60Sec;

/*
 * TIM2 Timer de ~30 sec pour veille de l'écran
 *
 * TIM3 Timer de 1 sec pour utilisation manuel
 *
 */

void Init_TIM2_Tempo(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	// 34 sec SI freq = 72MHz
	TIM2->ARR = 65534;
	TIM2->PSC = 38452;

	HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}


void Run_Tempo(void)
{
	Fin_Tempo = 0;
	TimHandle.Instance = TIM2;
	TIM2->CNT = 0;
	TIM2->DIER |= 0x01;
	TIM2->CR1  |= 0x01;
	TIM2->SR = 0;

	//	HAL_TIM_Base_Start_IT(&TimHandle);
	//	HAL_TIM_Base_Start(&TimHandle);
}

void Stop_Tempo(void)
{
	TimHandle.Instance = TIM2;
	Fin_Tempo = 0;
	TIM2->CR1  &= ~(0x01);
	TIM2->CNT = 0;
	// ce n'est pas redondant ?
	HAL_TIM_Base_Stop(&TimHandle);
}


void TIM2_IRQHandler(void)
{
	TimHandle.Instance=TIM2;

	__HAL_TIM_CLEAR_FLAG(&TimHandle, TIM_IT_UPDATE);
	HAL_TIM_Base_Stop(&TimHandle);

	Fin_Tempo = 1;
}

void Run_Pompe_1sec(void)
{
	Minute60Sec = 1;
	TIM3->CNT = 0;
	TIM3->DIER |= 0x01;
	TIM3->CR1  |= 0x01;
	TIM3->SR = 0;

	//	HAL_TIM_Base_Start_IT(&TimHandle);
	//	HAL_TIM_Base_Start(&TimHandle);
}

void Stop_Pompe_1sec(void)
{
	TimHandle.Instance = TIM3;
	TIM3->CNT = 0;
	TIM3->CR1  &= ~(0x01);
	HAL_TIM_Base_Stop(&TimHandle);
}

void Init_TIM3_Pompe_1sec(void)
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	// 1 sec SI freq = 72MHz
	TIM3->ARR = 65522;
	TIM3->PSC = 1281;

	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}


void TIM3_IRQHandler(void)
{
	TimHandle.Instance = TIM3;

	__HAL_TIM_CLEAR_FLAG(&TimHandle,TIM_IT_UPDATE);
	Minute60Sec--;

	if (Minute60Sec == 0)
	{
		Minute60Sec = 60;
		Compteur_Marche_Pompe--;
	}
}




