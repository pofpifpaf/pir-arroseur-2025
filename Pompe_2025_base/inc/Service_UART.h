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

void UART_Reception_Collection();
void Transmit_Ack(uint8_t n_capt, uint8_t type_data, uint8_t ack);

#endif /* SERVICE_UART_H_ */
