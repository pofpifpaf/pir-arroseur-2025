
#include <Machine_Etat.h>
#include "stm32f7xx.h"
#include "lvgl/lvgl.h"
#include <Projet.h>
#include <Prog_Tempo.h>
#include "RTC_Function.h"
#include "Utility_Flash.h"
#include <Ecran_Accueil.h>
#include <Ecran_Regle_Heure.h>
#include <Service_GPIO.h>
#include <Service_UART.h>
#include <Service_Timer.h>
#include "hal_stm_lvgl/tft/tft.h"
#include "stm32746g_discovery_ts.h"
#include "hal_stm_lvgl/tft/tft.h"
#include "hal_stm_lvgl/touchpad/touchpad.h"


void Error_Handler(void);
static void SystemClock_Config(void);
void PeriphCommonClock_Config(void);



GPIO_InitTypeDef MonGPIO_Init;
char state;   /*  Variable globale qui gère la machine à état */

RTC_TimeTypeDef Time_RTCF746;
RTC_DateTypeDef Date_RTCF746;

extern char Transi_2to0;
extern int Etat;
extern Data_Prog_Typedef Data_Prog;

int DATA_32[4] = {0xA2345679,0xbbeeaa55,0xcccc2222,0xabcdef} ;
char DATA_8[8] = {1,2,3,4,5,6,7,8} ;
char Vide[32];

int main(void)
{

    HAL_Init();
	/* Configure the system clock to 216 MHz */
	SystemClock_Config();
	PeriphCommonClock_Config();
	/* Enable I-Cache */
	SCB_EnableICache();
	/* Enable D-Cache */
	SCB_EnableDCache();

	Init_GPIO();
	MX_RTC_Init();
	lv_init();
	tft_init();
	touchpad_init();
	Init_TIM2_Tempo();
	Stop_Tempo();
	Init_TIM3_Pompe_1sec();

	Init_UART();

	// Relecture des données de programmation stockés en Flash
	Lire_Data_Prog(&Data_Prog);

	// Initialisation de la machine à état
	Transi_2to0 = 1;
    Etat = 2;

	while (1)
	{
		HAL_Delay(100);
        if (Change_Etat() == 1)
        {
        	Modifie_Etat();
        }
        else
        {
        	Refresh_Etat();
        	Gestion_Priorites();
        }
	}

}


/*************************************************************/
/****************Fin du main()********************************/
/*************************************************************/




void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */

void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC|RCC_PERIPHCLK_SAI2
                              |RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 384;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 5;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV8;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_8;
  PeriphClkInitStruct.Sai2ClockSelection = RCC_SAI2CLKSOURCE_PLLSAI;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLLSAIP;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}


