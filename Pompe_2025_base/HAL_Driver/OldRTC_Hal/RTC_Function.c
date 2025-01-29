
/***************   OLD ***********************/


#include "stm32f7xx_hal.h"
#include "RTC_Function.h"


RTC_HandleTypeDef RTC_F746;
extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;

extern void Error_Handler(void);


void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef Init_Time = {0};
  RTC_DateTypeDef Init_Date = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
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

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  Init_Time.Hours = 23;
  Init_Time.Minutes = 59;
  Init_Time.Seconds = 50;
  Init_Time.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  Init_Time.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&RTC_F746, &Init_Time, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  Init_Date.WeekDay = RTC_WEEKDAY_MONDAY;
  Init_Date.Month = RTC_MONTH_OCTOBER;
  Init_Date.Date = 28;
  Init_Date.Year = 24;
  if (HAL_RTC_SetDate(&RTC_F746, &Init_Date, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }

   /** Enable the TimeStamp
  */
  if (HAL_RTCEx_SetTimeStamp(&RTC_F746, RTC_TIMESTAMPEDGE_RISING, RTC_TIMESTAMPPIN_POS1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}


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

