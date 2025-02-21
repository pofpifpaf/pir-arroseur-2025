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

#define BUFFER_SIZE 25

extern UART_HandleTypeDef huart6;

extern uint8_t data_in;
extern uint8_t data_buffer[BUFFER_SIZE];
extern uint32_t counter;

void Verif_UART();

#define TOGGLE_PRISE 1
#define DATA_HUMIDITY 2


#endif /* SERVICE_UART_H_ */
