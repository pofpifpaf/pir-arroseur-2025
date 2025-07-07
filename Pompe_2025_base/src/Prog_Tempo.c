/*
 * Prog_Tempo.c
 *
 *  Created on: 25 avr. 2022
 *      Author: mahout
 */
#include "stm32f7xx.h"
#include <time.h>
#include <Service_GPIO.h>
#include <Service_UART.h>
#include <Prog_Tempo.h>
#include <Ecran_Lancer_Prog.h>
#include <Ecran_Lancer_Capteur.h>
#include "Utility_Flash.h"

#include <Ecran_Accueil.h>
#include <Ecran_Regle_Heure.h>
#include <Service_Timer.h>
#include <Machine_Etat.h>
#include "lvgl/lvgl.h"
#include "RTC_Function.h"

#include <Globals.h>


extern char Num_Prog_Courant;
extern Data_Prog_Typedef  Data_Prog;

extern char Prog_En_Marche[8];
extern int Etat;
extern int Mode_Manuel;


extern RTC_HandleTypeDef RTC_F746;
extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;

extern int capteur_active;

extern uint8_t mode;
extern uint8_t received_toggle_prise;
extern uint8_t zone;



/******************************************************************/
/*   Incrémente la n° courant de programme pour la page d'édition */
/******************************************************************/
void Increment_Numeprog(void)
{
	Num_Prog_Courant = Num_Prog_Courant + 1;

	if (Num_Prog_Courant > NumProgMax) Num_Prog_Courant = 1;
}


/******************************************************************/
/*   Decrémente la n° courant de programme pour la page d'édition */
/******************************************************************/
void Decrement_Numeprog(void)
{
	Num_Prog_Courant = Num_Prog_Courant - 1;

	if (Num_Prog_Courant < 1) Num_Prog_Courant = NumProgMax;
}

/******************************************************************/
/* Initialisation des données des programmes                      */
/* Ram[0] = Actif                                                 */
/* Ram[1] = Jour[1}                                               */
/* Ram[2] = H_start[1]                                            */
/* Ram[3] = M_start[1]                                            */
/* Ram[4] = H_Duree[1]                                            */
/* Ram[5] = M_Duree[1]                                            */
/* Ram[6] = H_start[2]                                            */
/*    .....                                                       */
/* Ram[32] = H_start[8]                                           */
/******************************************************************/
void Lire_Data_Prog(Data_Prog_Typedef *Data)
{
	char Tempo[8 * NumProgMax + 1];

	Read_Byte_Flash(FLASH_USER_START_ADDR, 8*NumProgMax+1, Tempo);

	for (int i = 0 ; i < NumProgMax ; i++)
	{
		Data->Prog_Actif = Tempo[i*8];
		Data->M_Stop[i] = Tempo[i*8+1];
		Data->M_Start[i]= Tempo[i*8+2];
		Data->M_Duree[i] = Tempo[i*8+3];
		Data->Jour_Stop[i] = Tempo[i*8+4];
		Data->Jour[i] = Tempo[i*8+5];
		Data->H_Stop[i] = Tempo[i*8+6];
		Data->H_Start[i] = Tempo[i*8+7];
		Data->H_Duree[i] = Tempo[i*8+8];
	}
}

/******************************************************************/
/* Program data saving                                            */
/* en RAM de la DS1307                                            */
/* Ram[0] = Actif                                                 */
/* Ram[1] = H_start[1]                                            */
/* Ram[2] = M_start[1]                                            */
/* Ram[3] = H_Duree[1]                                            */
/* Ram[4] = M_Duree[1]                                            */
/* Ram[5] = H_start[2]                                            */
/*    .....                                                       */
/* Ram[32] = H_start[8]                                           */
/******************************************************************/
void Stocke_Data_Prog(Data_Prog_Typedef *Data)
{
	char Tempo[8 * NumProgMax + 1];

	Tempo[0] = Data->Prog_Actif;

	for(int k = 0 ; k < NumProgMax ; k++)
	{
	    Tempo[k*8+1] = Data->M_Stop[k];
	    Tempo[k*8+2] = Data->M_Start[k];
	    Tempo[k*8+3] = Data->M_Duree[k];
	    Tempo[k*8+4] = Data->Jour_Stop[k];
	    Tempo[k*8+5] = Data->Jour[k];
	    Tempo[k*8+6] = Data->H_Stop[k];
	    Tempo[k*8+7] = Data->H_Start[k];
	    Tempo[k*8+8] = Data->H_Duree[k];
	}

	Erase_Flash();
	Write_Byte_Flash(FLASH_USER_START_ADDR, 8 * NumProgMax + 1, (char*)(Tempo));
}

/******************************************************************/
/*                 Program scheduling main function               */
/******************************************************************/
void Verif_Programme()
{
		HAL_RTC_GetTime(&RTC_F746, &Time_RTCF746, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&RTC_F746, &Date_RTCF746, RTC_FORMAT_BIN);

		if (isInProgram(&Data_Prog, Time_RTCF746, Date_RTCF746))
		{
			Set_Outlet_ON();
		}
		else
		{
			Set_Outlet_OFF();
		}
}

/*
 * Data->Jour[i] is coded on the first 7 bits:
 * 		01000000 = sunday
 * 		01100000 = sunday and saturday
 * 		00100001 = saturday and monday
 * Date_RTCF746->Weekday():
 * 		1 = monday
 * 		2 = tuesday
 * 		3 = wednesday
 * 		...
 *
 * 		#define LL_RTC_WEEKDAY_MONDAY   ((uint8_t)0x01U)
 *
 */
char isInProgram(Data_Prog_Typedef* Data, RTC_TimeTypeDef Time_RTCF746, RTC_DateTypeDef Date_RTCF746)
{
	int i;
	char inProgram = 0;

	for (i = 0 ; i < NumProgMax ; i++)
	{
		if (Prog_En_Marche[i] == 1)
		{
			Data->Jour[i] &= ~(0x80);

			if (((Data->Jour[i] & (0x1 << (Date_RTCF746.WeekDay-1))) != 0))
			{
				inProgram |=
							((Time_RTCF746.Hours > Data->H_Start[i])
							&& (Time_RTCF746.Hours < Data->H_Stop[i]))

							|| ((Time_RTCF746.Hours == Data->H_Start[i])
							&& (Data->H_Stop[i] > Data->H_Start[i])
							&& (Time_RTCF746.Minutes > Data->M_Start[i]))

							|| ((Time_RTCF746.Hours == Data->H_Stop[i])
							&& (Data->H_Stop[i] > Data->H_Start[i])
							&& (Time_RTCF746.Minutes < Data->M_Stop[i]))

							|| ((Time_RTCF746.Hours == Data->H_Stop[i])
							&& (Data->H_Stop[i] == Data->H_Start[i])
							&& (Time_RTCF746.Minutes < Data->M_Stop[i])
							&& (Time_RTCF746.Minutes > Data->M_Start[i]))
							;
			}
		}
	}

	return inProgram;
}

uint8_t prev_zone = 0;
uint8_t compteur_toggle = 0;

//
//
//
void Gestion_Priorites(void)
{
	UART_Reception_Collection();

	if (received_toggle_prise)
	{
		if (compteur_toggle > 10000) // approximately 100s
		{
			compteur_toggle = 0;
			received_toggle_prise = 0;
		}
		else
		{
			compteur_toggle++;
		}
	}

	if (capteur_active && !received_toggle_prise && (!Mode_Manuel) && (Etat != PROGRAM_CONFIGURATION_MODE))
	{
		switch (mode)
		{
		case MODE_HYSTERESIS :

			if (prev_zone == 0 && (zone == 1 || zone == 2))
			{
				Set_Outlet_OFF();
			}
			if (prev_zone == 2 && (zone == 0 || zone == 1))
			{
				Set_Outlet_ON();
			}
			break;

		case MODE_TWOTHRESHOLD :

			switch (zone)
			{
			case 0 :
				Set_Outlet_ON();
				break;
			case 1 :
				Verif_Programme();
				break;
			case 2 :
				Set_Outlet_OFF();
				break;
			default :
				break;
			}

			break;

		default :
			break;
		}

		prev_zone = zone;
	}

}






