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
#include "Utility_Flash.h"

#include <Ecran_Accueil.h>
#include <Ecran_Regle_Heure.h>
#include <Service_Timer.h>
#include <Machine_Etat.h>
#include "lvgl/lvgl.h"
#include <Projet.h>
#include "RTC_Function.h"




char Num_Prog_Courant;
Data_Prog_Typedef  Data_Prog;

extern char Prog_En_Marche[8];
extern int Etat ;
extern int Mode_Manuel ;


extern RTC_HandleTypeDef RTC_F746;
extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;



/******************************************************************/
/*   Incrémente la n° courant de programme pour la page d'édition */
/******************************************************************/
void Increment_Numeprog(void)
{
	Num_Prog_Courant = Num_Prog_Courant + 1;

	if (Num_Prog_Courant > NumProgMax)
	{
		Num_Prog_Courant = 1;
	}
}


/******************************************************************/
/*   Decrémente la n° courant de programme pour la page d'édition */
/******************************************************************/
void Decrement_Numeprog(void)
{
	Num_Prog_Courant = Num_Prog_Courant - 1;

	if (Num_Prog_Courant < 1)
	{
		Num_Prog_Courant = NumProgMax;
	}
}

// Faire en sorte qu'il écrit pas en flash à chaque fois
/******************************************************************/
/* Initialisation des données des programmes                      */
/* Lecture de la RAM dee la DS1307                                */
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
/* Sauvegarde des données des programmes                          */
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
/*   Fonction de vérification si on doit allumer ou non la prise */
/******************************************************************/
void Verif_Programme()
{
		HAL_RTC_GetTime(&RTC_F746, &Time_RTCF746, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&RTC_F746, &Date_RTCF746, RTC_FORMAT_BIN);

		calculateStopTime(&Data_Prog);

		if (isInProgram(&Data_Prog,Time_RTCF746,Date_RTCF746))
		{
			Allume_Prise();
		}
		else
		{
			Eteint_Prise();
		}
}
/*************************************************************************/
/*   Fonction de calcul de l'heure et du jour de fin de chaque programme */
/*************************************************************************/
void calculateStopTime(Data_Prog_Typedef* Data)
{
	int JStop, MStop, HStop, retH, retM;

	for (int i = 0; i < NumProgMax; i++)
	{
		retM = 0;
		retH = 0;

		MStop = Data->M_Start[i] + Data->M_Duree[i];
		if (MStop >= 60)
		{
			MStop = MStop - 60;
			retM = 1;
		}

		HStop = Data->H_Start[i] + Data->H_Duree[i] + retM;
		if (HStop >= 24)
		{
			HStop = HStop - 24;
			retH = 1;
		}

		JStop = (Data->Jour[i] << retH) | (Data->Jour[i] >> (7-retH)) ;
		JStop &= ~(0x80) ;  //efface le bit numéro 7

		Data->Jour_Stop[i] = (char)(JStop);
		Data->H_Stop[i] = (char)(HStop);
		Data->M_Stop[i] = (char)(MStop);
	}
}


char isInProgram(Data_Prog_Typedef* Data, RTC_TimeTypeDef Time_RTCF746, RTC_DateTypeDef Date_RTCF746)
{
	int i;
	char notInProgram = 0;

	for (i = 0 ; i < NumProgMax ; i++)
	{
		if (Prog_En_Marche[i] == 1)
		{
			// On est sur le jour de début et de fin
			if ((Data->Jour[i] == Data->Jour_Stop[i])
				&& ((Data->Jour[i] & (0x1 << (Date_RTCF746.WeekDay-1))) != 0))
			{
				notInProgram = ((Time_RTCF746.Hours > Data->H_Start[i])
							&& (Time_RTCF746.Hours < Data->H_Stop[i]))

							|| ((Time_RTCF746.Hours == Data->H_Start[i])
							&& (Time_RTCF746.Minutes >= Data->M_Start[i]))

							|| ((Time_RTCF746.Hours == Data->H_Stop[i])
							&& (Time_RTCF746.Minutes <= Data->M_Stop[i]));
			}
			// On est sur le jour de début mais pas de fin
			else if ((Data->Jour[i] & (0x1 << (Date_RTCF746.WeekDay-1))) != 0)
			{
				notInProgram = (Time_RTCF746.Hours > Data->H_Start[i])

							|| ((Time_RTCF746.Hours == Data->H_Start[i])
							&& (Time_RTCF746.Minutes >= Data->M_Start[i]));
			}
			// On est sur le jour de fin mais pas de début
			else if ((Data->Jour_Stop[i] & (0x1 << (Date_RTCF746.WeekDay-1))) != 0)
			{
				notInProgram = (Time_RTCF746.Hours < Data->H_Stop[i])

							|| ((Time_RTCF746.Hours == Data->H_Stop[i])
							&& (Time_RTCF746.Minutes <= Data->M_Stop[i]));
			}

		}
	}

	return !notInProgram;
}


void Gestion_Priorites(void)
{
	if ((!Mode_Manuel) && (Etat != 30))
	{
		//Verif_Programme();
		Verif_UART();
	}


}






