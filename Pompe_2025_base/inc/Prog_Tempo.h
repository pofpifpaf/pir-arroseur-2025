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
	  char Prog_Actif;					// Booléen, vrai si le mode programme est activé // Quel est l'interet ?
	  char Jour[NumProgMax];			// Jour de début du programme
	  char H_Start[NumProgMax];			// Heure de début du programme
	  char M_Start[NumProgMax];			// Minute de début du programme
	  char H_Duree[NumProgMax];			// Nombre d'heures de durée du programme
	  char M_Duree[NumProgMax];			// Nombre de minutes de durée du programme
	  char Jour_Stop[NumProgMax];       // Jour de fin du programme
	  char H_Stop[NumProgMax];  		// Heure de fin du programme
	  char M_Stop[NumProgMax];			// Minute de fin du programme
	} Data_Prog_Typedef;

	void Increment_Numeprog(void);
	void Decrement_Numeprog(void);
	void Lire_Data_Prog( Data_Prog_Typedef *);
	void Stocke_Data_Prog(Data_Prog_Typedef *);
	char isInProgram(Data_Prog_Typedef  * , RTC_TimeTypeDef, RTC_DateTypeDef );
	void calculateStopTime(Data_Prog_Typedef  *);
	void Verif_Programme(void);
	void Gestion_Priorites(void);

#endif /* PROG_TEMPO_H_ */
