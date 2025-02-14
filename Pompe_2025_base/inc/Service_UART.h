/*
 * Service_UART.h
 *
 *  Created on: Feb 7, 2025
 *      Author: adamg
 */



#ifndef SERVICE_UART_H_
#define SERVICE_UART_H_

#include "stm32f7xx.h"

void Init_UART();

extern UART_HandleTypeDef huart6;

extern uint8_t data_in;
extern uint8_t data_buffer[100];
extern uint32_t counter;

#endif /* SERVICE_UART_H_ */
