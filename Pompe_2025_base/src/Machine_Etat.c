/*
 * Machine_Etat.c
 *
 *  Created on: 18 juil. 2021
 *      Author: mahout
 *
 *  Voir machine à état drive
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

char Change;
char Transi_0to1;
char Transi_0to3;
char Transi_0to4;
char Transi_1to0;
char Transi_2to0;
char Transi_0to2;
char Transi_3to0 ;
char Transi_3to3 ;
char Transi_4to4 ;
char Transi_4to0 ;
char Transi_30to0,Transi_0to30,Transi_30to30;
int Bouton = 0;
int Default = 1 ;
char Poussoir_Start_Appui;
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
/*           EVOLUTION DE LA MACHINE                            */
/****************************************************************/
char  Change_Etat(void)
/****************************************************************/
{
	Change = 0;

	if (Etat == 0)
	{
		if (Transi_0to1 == 1)
		{
			Etat = 1;
			Change = 1;
			Transi_0to1 = 0;
			Stop_Tempo();
		}
		if (Fin_Tempo == 1)
		{
			Etat = -1;
			Change = 1;
			Fin_Tempo = 0;
		}
		if (Transi_0to2 == 1)
		{
			Etat = 2;
			Change = 1;
			Transi_0to2 = 0;
			Poussoir_Start_Appui = 0;
			Stop_Tempo();
		}
		if (Transi_0to30 == 1)
		{
			Etat = 30;
			Change = 1;
			Transi_0to30 = 0;
			Stop_Tempo();
		}
		if (Transi_0to3 == 1)
		{
			Etat = 3;
			Change = 1;
			Transi_0to3 = 0;
			Stop_Tempo();
		}
		if (Transi_0to4 == 1)
		{
			Etat = 4 ;
			Change = 1 ;
			Transi_0to4 = 0;
			Stop_Tempo();
		}
		if (Poussoir_Start_Appui == 1)
		{
			Etat = 2;
			Change = 1;
			Poussoir_Start_Appui = 0;
			Bouton = 1;
			Stop_Tempo();
		}
	}

	if(Etat == 1 && Transi_1to0 == 1)
	{
		Etat = 0;
		Change = 1;
		Transi_1to0 = 0;
	}

	if(Etat == 3)
	{
		if (Transi_3to0 == 1)
		{
			Etat = 0;
			Change = 1;
			Transi_3to0 = 0;
		}
		if (Transi_3to3 == 1)
		{
			Etat = 3;
			Change = 1;
			Transi_3to3 = 0;
		}
	}

	if(Etat == 30)
	{
		if (Transi_30to30 == 1)
		{
			Etat = 30;
			Change = 1;
			Transi_30to30 = 0;
		}
		if (Transi_30to0 == 1)
		{
			Etat = 0;
			Change = 1;
			Transi_30to0 = 0;
		}
	}

	if(Etat == -1)
	{
		BSP_TS_GetState(&TS_State);
		if(TS_State.touchDetected || Poussoir_Start_Appui==1)
		{
			LCD_DisplayOn();
			Etat = 0;
			Change = 1;
			Poussoir_Start_Appui=0;
		}
	}
	if(Etat == 2)
	{
		if (Transi_2to0 == 1)
		{
			Etat = 0;
			Change = 1;
			Transi_2to0 = 0;
			Poussoir_Start_Appui = 0;
		}
		if (Compteur_Marche_Pompe < 0)
		{
			lv_obj_del(Texte_Marche);
			lv_obj_del(spinner);
			A_Effacer = 0;
			Eteint_Pompe();
			Stop_Pompe_1sec();
			Compteur_Marche_Pompe = TempoMini;
			Mode_Manuel = 0;
			Minute60Sec = 0;
		}
		if (Poussoir_Start_Appui==1)
		{
			Etat = 2;
			Change = 1;
			Poussoir_Start_Appui = 0;
			Bouton = 1;
			Default = 0;
		}
	}
	if (Etat == 4)
	{
		if (Transi_4to0 == 1)
		{
			Etat = 0;
			Change = 1 ;
			Transi_4to0 = 0 ;
		}
		if (Transi_4to4 == 1)
		{
			Etat = 4;
			Change = 1 ;
			Transi_4to4 = 0 ;
		}
	}

	return (Change);
}

/****************************************************************/
/*           ACTIONS Suite à un changement d'état                */
/****************************************************************/
void Modifie_Etat(void)
/****************************************************************/
{

	if (Etat == 0)
	{
		// Etat Accueil
		Creer_Ecran_Acceuil();
		Run_Tempo();
		Num_Prog_Courant = 0;
		Prog_Selected = 0;
	}
	if (Etat == 1)
	{
		// Etat Reglage Heure
		Creer_Ecran_Regle_Heure();
	}
	if (Etat == -1)
	{
		// Etat Ecran Mode Veille
		LCD_DisplayOff();
	}
	if (Etat == 2)
	{
		// Etat Mode Pilotage Manuel
		Transi_0to2 = 0;
		Creer_Ecran_Marche();
		Refresh_Slider(Compteur_Marche_Pompe);
	}
	if (Etat == 30)
	{
		// Etat Réglage Programme
		Transi_30to30 = 0;
		Creer_Ecran_Regle_Prog();
	}
	if (Etat == 3)
	{
		// Etat Lancement de Programme
		Creer_Ecran_Lancer_Prog() ;
	}
	if (Etat== 4)
	{
		// Etat Mode Capteur
		Creer_Ecran_Lancer_Capteur() ;
	}

}

/****************************************************************/
/*                   ACTIONS permanentes                        */
/****************************************************************/
void Refresh_Etat(void)
/****************************************************************/
{
	if (Etat == 0)
	{
		// Affichage heure et date sur l'accueil
		HAL_RTC_GetTime(&RTC_F746, &Time_RTCF746, RTC_FORMAT_BIN);
		Change_Heure(Time_RTCF746.Hours, Time_RTCF746.Minutes, Time_RTCF746.Seconds);
		HAL_RTC_GetDate(&RTC_F746, &Date_RTCF746, RTC_FORMAT_BIN);
		Change_Date(Date_RTCF746.Date, Date_RTCF746.Month, Date_RTCF746.Year);
		lv_task_handler();
	}
	if (Etat == 2)
	{
		Refresh_Slider(Compteur_Marche_Pompe);
	}
}



