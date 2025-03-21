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
extern uint8_t seuil_high;


void Verif_UART();
void Transmit_Ack(uint8_t n_capt, uint8_t type_data, uint8_t ack);

#define TOGGLE_PRISE 1
#define DATA_HUMIDITY 2


#endif /* SERVICE_UART_H_ */
