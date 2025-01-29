/*
 * Service_Timer.h
 *
 *  Created on: 15 juil. 2021
 *      Author: mahout
 */

#ifndef SERVICE_TIMER_H_
#define SERVICE_TIMER_H_

void Init_TIM2_Tempo(void);
void Stop_Tempo(void);
void Run_Tempo(void);
void Init_TIM3_Pompe_1sec(void);
void TIM3_IRQHandler(void);
void TIM2_IRQHandler(void);
void Run_Pompe_1sec(void);
void Stop_Pompe_1sec(void);

#endif /* SERVICE_TIMER_H_ */
