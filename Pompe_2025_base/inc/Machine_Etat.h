/*
 * Machine_Etat.h
 *
 *  Created on: 18 juil. 2021
 *      Author: mahout
 */

#ifndef MACHINE_ETAT_H_
#define MACHINE_ETAT_H_

	#define HOME 0
	#define TIME_CONFIGURATION_MODE 1
	#define MANUAL_OPERATION_MODE 2
	#define PROGRAM_MODE 3
	#define SENSOR_MODE 4
	#define PROGRAM_CONFIGURATION_MODE 5
	#define SLEEP_MODE 6

char Change_Etat(void);
void Modifie_Etat(void);
void Refresh_Etat(void);
void Init_TIM3_Pompe_1sec(void);


#endif /* MACHINE_ETAT_H_ */
