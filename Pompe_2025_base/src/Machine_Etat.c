/*
 * Machine_Etat.c
 *
 *  Created on: 18 juil. 2021
 *      Author: mahout
 *
 *
 *
 */

#include "stm32f7xx.h"
#include <Machine_Etat.h>
#include <Ecran_Accueil.h>
#include <Ecran_Marche.h>
#include <Ecran_Marche.h>
#include <Ecran_Regle_Prog.h>
#include <Ecran_Lancer_Prog.h>
#include <Ecran_Regle_Heure.h>
#include <Ecran_Lancer_Capteur.h>
#include <Service_Timer.h>
#include <Service_GPIO.h>
#include "RTC_Function.h"
#include "stm32746g_discovery_ts.h"
#include "hal_stm_lvgl/tft/tft.h"
#include "hal_stm_lvgl/touchpad/touchpad.h"
#include "lvgl/lvgl.h"
#include <Projet.h>

int Etat;

extern void LCD_DisplayOn(void);
extern void LCD_DisplayOff(void);

/*
 * STATE MACHINE DEFINITION
 *
	#define HOME 0
	#define TIME_CONFIGURATION_MODE 1
	#define MANUAL_OPERATION_MODE 2
	#define PROGRAM_MODE 3
	#define SENSOR_MODE 4
	#define PROGRAM_CONFIGURATION_MODE 5
	#define SLEEP_MODE 6

 */

char Change;
char Transi_0to1, Transi_1to0;
char Transi_0to3, Transi_3to0, Transi_3to3;
char Transi_0to2, Transi_2to0;
char Transi_4to0, Transi_0to4, Transi_4to4;
char Transi_5to0, Transi_0to5, Transi_5to5;

int Bouton = 0;
int Default = 1 ;
char Start_Button_Pushed;
char Fin_Tempo;
char Minute60Sec ;
int Compteur_Marche_Pompe = 20 ;
TS_StateTypeDef  TS_State;

extern char Prog_Selected ;
extern char Prog_En_Marche[8] ;
extern lv_obj_t * spinner ;
extern lv_obj_t * Texte_Marche;
extern int A_Effacer ;
extern int TempoMini ;
extern int Mode_Manuel ;
extern RTC_HandleTypeDef RTC_F746;
extern RTC_TimeTypeDef Time_RTCF746;
extern RTC_DateTypeDef Date_RTCF746;
extern char Num_Prog_Courant;




/****************************************************************/
/*                      STATE CHANGE                            */
/****************************************************************/
char Change_Etat(void)
/****************************************************************/
{
	Change = 0;

	switch(Etat)
	{
	case HOME :
		if (Fin_Tempo)
		{
			Etat = SLEEP_MODE;
			Change = 1;
			Fin_Tempo = 0;
		}
		else if (Transi_0to2)
		{
			Etat = MANUAL_OPERATION_MODE;
			Change = 1;
			Transi_0to2 = 0;
			Start_Button_Pushed = 0;
			Stop_Tempo();
		}
		else if (Transi_0to1)
		{
			Etat = TIME_CONFIGURATION_MODE;
			Change = 1;
			Transi_0to1 = 0;
			Stop_Tempo();
		}
		else if (Transi_0to5)
		{
			Etat = PROGRAM_CONFIGURATION_MODE;
			Change = 1;
			Transi_0to5 = 0;
			Stop_Tempo();
		}
		else if (Transi_0to3)
		{
			Etat = PROGRAM_MODE;
			Change = 1;
			Transi_0to3 = 0;
			Stop_Tempo();
		}
		else if (Transi_0to4)
		{
			Etat = SENSOR_MODE;
			Change = 1;
			Transi_0to4 = 0;
			Stop_Tempo();
		}
		else if (Start_Button_Pushed)
		{
			Etat = MANUAL_OPERATION_MODE;
			Change = 1;
			Start_Button_Pushed = 0;
			Bouton = 1;
			Stop_Tempo();
		}
		break;

	case TIME_CONFIGURATION_MODE :
		if (Transi_1to0)
		{
			Etat = HOME;
			Change = 1;
			Transi_1to0 = 0;
		}
		break;

	case PROGRAM_MODE :
		if (Transi_3to0)
		{
			Etat = HOME;
			Change = 1;
			Transi_3to0 = 0;
		}
		else if (Transi_3to3)
		{
			Etat = PROGRAM_MODE;
			Change = 1;
			Transi_3to3 = 0;
		}
		break;

	case PROGRAM_CONFIGURATION_MODE :
		if (Transi_5to5)
		{
			Etat = PROGRAM_CONFIGURATION_MODE;
			Change = 1;
			Transi_5to5 = 0;
		}
		else if (Transi_5to0)
		{
			Etat = HOME;
			Change = 1;
			Transi_5to0 = 0;
		}
		break;

	case SLEEP_MODE :
		BSP_TS_GetState(&TS_State);
		if(TS_State.touchDetected || Start_Button_Pushed)
		{
			LCD_DisplayOn();
			Etat = HOME;
			Change = 1;
			Start_Button_Pushed = 0;
		}
		break;

	case MANUAL_OPERATION_MODE :
		if (Transi_2to0)
		{
			Etat = HOME;
			Change = 1;
			Transi_2to0 = 0;
			Start_Button_Pushed = 0;
		}
		else if (Start_Button_Pushed)
		{
			Etat = MANUAL_OPERATION_MODE;
			Change = 1;
			Start_Button_Pushed = 0;
			Bouton = 1;
			Default = 0;
		}
		if (Compteur_Marche_Pompe < 0)
		{
			lv_obj_del(Texte_Marche);
			lv_obj_del(spinner);

			A_Effacer = 0;

			Eteint_Prise();
			Stop_Pompe_1sec();

			Compteur_Marche_Pompe = TempoMini;
			Mode_Manuel = 0;
			Minute60Sec = 0;
		}
		break;

	case SENSOR_MODE :
		if (Transi_4to0)
		{
			Etat = HOME;
			Change = 1 ;
			Transi_4to0 = 0 ;
		}
		else if (Transi_4to4)
		{
			Etat = SENSOR_MODE;
			Change = 1;
			Transi_4to4 = 0;
		}
		break;

	default : break;
	}

	return (Change);
}

/****************************************************************/
/*           ACTIONS Suite à un changement d'état                */
/****************************************************************/
void Modifie_Etat(void)
/****************************************************************/
{
	switch(Etat)
	{
	case HOME :
		Creer_Ecran_Acceuil();
		Run_Tempo();
		Num_Prog_Courant = 0;
		Prog_Selected = 0;
		break;

	case TIME_CONFIGURATION_MODE :
		Creer_Ecran_Regle_Heure();
		break;

	case SLEEP_MODE :
		LCD_DisplayOff();
		break;

	case MANUAL_OPERATION_MODE :
		Transi_0to2 = 0;
		Creer_Ecran_Marche();
		Refresh_Slider(Compteur_Marche_Pompe);
		break;

	case PROGRAM_CONFIGURATION_MODE :
		Transi_5to5 = 0;
		Creer_Ecran_Regle_Prog();
		break;

	case PROGRAM_MODE :
		Creer_Ecran_Lancer_Prog();
		break;

	case SENSOR_MODE :
		Creer_Ecran_Lancer_Capteur();
		break;

	default : break;

	}

}

/****************************************************************/
/*                   ACTIONS permanentes                        */
/****************************************************************/
void Refresh_Etat(void)
/****************************************************************/
{
	switch (Etat)
	{
	case HOME :
		// Affichage heure et date sur l'accueil
		HAL_RTC_GetTime(&RTC_F746, &Time_RTCF746, RTC_FORMAT_BIN);
		Change_Heure(Time_RTCF746.Hours, Time_RTCF746.Minutes, Time_RTCF746.Seconds);
		HAL_RTC_GetDate(&RTC_F746, &Date_RTCF746, RTC_FORMAT_BIN);
		Change_Date(Date_RTCF746.Date, Date_RTCF746.Month, Date_RTCF746.Year);
		lv_task_handler();
		break;

	case MANUAL_OPERATION_MODE :
		Refresh_Slider(Compteur_Marche_Pompe);
		break;

	default : break;
	}
}



