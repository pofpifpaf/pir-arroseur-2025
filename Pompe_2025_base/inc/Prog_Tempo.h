/*
 * Prog_Tempo.h
 *
 *  Created on: 25 avr. 2022
 *      Author: mahout
 */

#ifndef PROG_TEMPO_H_
#define PROG_TEMPO_H_

	#define NumProgMax 8

	typedef struct
	{
	  char Prog_Actif;
	  char Jour[NumProgMax];
	  char H_Start[NumProgMax];
	  char M_Start[NumProgMax];
	  char H_Duree[NumProgMax];
	  char M_Duree[NumProgMax];
	  char Jour_Stop[NumProgMax];
	  char H_Stop[NumProgMax];
	  char M_Stop[NumProgMax];
	}Data_Prog_Typedef;

	void Increment_Numeprog(void);
	void Decrement_Numeprog(void);
	void Lire_Data_Prog( Data_Prog_Typedef *);
	void Stocke_Data_Prog(Data_Prog_Typedef *);
	char  Is_Start(Data_Prog_Typedef  * , RTC_TimeTypeDef, RTC_DateTypeDef );
	void CheckStop(Data_Prog_Typedef  *);
	void Verif_Programme(void);
	void Gestion_Priorites(void);

#endif /* PROG_TEMPO_H_ */
