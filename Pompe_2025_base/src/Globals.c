#include "stm32f7xx_hal.h"

#include <Prog_Tempo.h>

int Etat;
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
char Minute60Sec;
int Compteur_Marche_Pompe = 20;

RTC_TimeTypeDef Time_RTCF746;
RTC_DateTypeDef Date_RTCF746;

char Num_Prog_Courant;
Data_Prog_Typedef  Data_Prog;


RTC_HandleTypeDef RTC_F746;

uint8_t received_toggle_prise;
uint8_t zone;


uint16_t seuil_capteur_high = 0;
uint16_t seuil_capteur_low = 0;

int capteur_active;
uint8_t mode;


char Prog_Selected;
char Prog_En_Marche[8];

int TempoMini = 20;

int A_Effacer = 0;
int Mode_Manuel = 0;
