/***************   NEW ***********************/

#include "stm32f7xx_hal.h"
#include "RTC_Function.h"


RTC_HandleTypeDef RTC_F746;
extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;

void RTC_Clock(void) ;

extern void Error_Handler(void);




/*------------------------------------ RTC configuration --------------------------------------*/

/**
* @brief RTC MSP Initialization
* This function configures the hardware resources used in this example
* @param hrtc: RTC handle pointer
* @retval None
*/
void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(hrtc->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */

  }

}

void MX_RTC_Init(void)
{

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  RTC_F746.Instance = RTC;
  RTC_F746.Init.HourFormat = RTC_HOURFORMAT_24;
  RTC_F746.Init.AsynchPrediv = 127;
  RTC_F746.Init.SynchPrediv = 255;
  RTC_F746.Init.OutPut = RTC_OUTPUT_DISABLE;
  RTC_F746.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  RTC_F746.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

  if (HAL_RTC_Init(&RTC_F746) != HAL_OK)
  {
	  Error_Handler();
  }

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x3;
  sTime.Minutes = 0x59;
  sTime.Seconds = 0x50;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;

  if (HAL_RTC_SetTime(&RTC_F746, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }

  sDate.WeekDay = RTC_WEEKDAY_FRIDAY;
  sDate.Month = RTC_MONTH_NOVEMBER;
  sDate.Date = 0x8;
  sDate.Year = 0x24;

  if (HAL_RTC_SetDate(&RTC_F746, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
}


/////////////////////////// A l'air d'être inutile, n'est appelé nulle part
void RTC_CalendarConfig(void)
{
  RTC_DateTypeDef sdatestructure;
  RTC_TimeTypeDef stimestructure;

  /*##-1- Configure the Date #################################################*/
  /* Set Date: Tuesday February 18th 2014 */
  sdatestructure.Year = 23;
  sdatestructure.Month = RTC_MONTH_APRIL;
  sdatestructure.Date = 29;
  sdatestructure.WeekDay = RTC_WEEKDAY_SATURDAY;

  if(HAL_RTC_SetDate(&RTC_F746,&sdatestructure,RTC_FORMAT_BCD) != HAL_OK)
  {
    /* Initialization Error
     *  */
    Error_Handler();
  }

  /*##-2- Configure the Time #################################################*/
  /* Set Time: 02:00:00 */
  stimestructure.Hours = 21;
  stimestructure.Minutes = 13;
  stimestructure.Seconds = 45;
  stimestructure.TimeFormat = RTC_HOURFORMAT_24;               //RTC_HOURFORMAT12_AM;
  stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
  stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

  if (HAL_RTC_SetTime(&RTC_F746, &stimestructure, RTC_FORMAT_BCD) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-3- Writes a data in a RTC Backup data Register1 #######################*/
  HAL_RTCEx_BKUPWrite(&RTC_F746, RTC_BKP_DR1, 0x32F2);
}

/**
  * @brief  Display the current time and date.
  * @param  showtime : pointer to buffer
  * @param  showdate : pointer to buffer
  * @retval None
  */
void RTC_CalendarShow(uint8_t *showtime, uint8_t *showdate)
{
  RTC_DateTypeDef Date_RTCF746;
  RTC_TimeTypeDef Time_RTCF746;

  /* Get the RTC current Time */
  HAL_RTC_GetTime(&RTC_F746, &Time_RTCF746, RTC_FORMAT_BIN);
  /* Get the RTC current Date */
  HAL_RTC_GetDate(&RTC_F746, &Date_RTCF746, RTC_FORMAT_BIN);

}
