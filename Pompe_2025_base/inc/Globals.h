/*
 * Globals.h
 *
 * Variable declaration
 *
 */
#ifndef GLOBALS_H
#define GLOBALS_H

#include "stm32f7xx_hal.h"

#include <Prog_Tempo.h>

// State Machine

	#define HOME 0
	#define TIME_CONFIGURATION_MODE 1
	#define MANUAL_OPERATION_MODE 2
	#define PROGRAM_MODE 3
	#define SENSOR_MODE 4
	#define PROGRAM_CONFIGURATION_MODE 5
	#define SLEEP_MODE 6

extern int Etat;
extern char Change;
extern char Transi_0to1, Transi_1to0;
extern char Transi_0to3, Transi_3to0, Transi_3to3;
extern char Transi_0to2, Transi_2to0;
extern char Transi_4to0, Transi_0to4, Transi_4to4;
extern char Transi_5to0, Transi_0to5, Transi_5to5;

extern int Bouton;
extern int Default;
extern char Start_Button_Pushed;
extern char Fin_Tempo;
extern char Minute60Sec;
extern int Compteur_Marche_Pompe;

// Program mode

extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;

extern char Num_Prog_Courant;
extern Data_Prog_Typedef  Data_Prog;

// RTC Function

extern RTC_HandleTypeDef RTC_F746;

// UART

extern uint8_t received_toggle_prise;
extern uint8_t zone;

	#define TOGGLE_PRISE 1
	#define DATA_HUMIDITY 2

// Capteurs

extern uint16_t seuil_capteur_high;
extern uint16_t seuil_capteur_low;

extern int capteur_active;
extern uint8_t mode;

// Program State

extern char Prog_Selected;
extern char Prog_En_Marche[8];

// Ecran Marche

extern int TempoMini;

extern int A_Effacer;
extern int Mode_Manuel;



#endif
