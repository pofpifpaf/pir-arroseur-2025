/*
 * Driver_USART_HAL.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Eliphée
 */

#ifndef SRC_DRIVER_USART_HAL_H_
#define SRC_DRIVER_USART_HAL_H_

#define DATA_SWITCH 1
#define DATA_HUM 2

#define const1 (60/2375)
#define const2 (0.4*(4095-2375))

#include "stm32l0xx_hal.h"
#include <string.h>
#include "main.h"

void Send_Trame(uint8_t NumCapteur, uint8_t TypeDonnee, uint16_t Info, UART_HandleTypeDef* huart);

int getValue(ADC_HandleTypeDef* hadc);

int isAck(uint8_t NumCapteur, uint8_t TypeDonnee, uint8_t OctetRecu);

#endif /* SRC_DRIVER_USART_HAL_H_ */
