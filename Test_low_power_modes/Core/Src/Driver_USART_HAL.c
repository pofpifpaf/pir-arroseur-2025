
#include "Driver_USART_HAL.h"

void Send_Trame (uint8_t NumCapteur, uint8_t TypeDonnee, uint16_t Info, UART_HandleTypeDef* huart){
	//Définition du delai utilisé pour le transmit
	uint32_t delai = 50;

	//Concatenation de NumCapteur et TypeDonnee dans un seul octet
	uint8_t Octet_NumEtType = (NumCapteur & 0x0F) << 4 | (TypeDonnee & 0x0F);

	//On split les données contenues dans Info (16bits) dans deux octets distincts
	//On décale vers la droite les 8 premiers bits de Info, puis on les récupère avec un masque ET
	uint8_t Octet_Info_Split_1 = (Info >> 8) & 0xFF;
	uint8_t Octet_Info_Split_2 = Info & 0xFF;

	HAL_UART_Transmit(huart, &Octet_NumEtType, sizeof(Octet_NumEtType), delai);
	HAL_UART_Transmit(huart, &Octet_Info_Split_1, sizeof(Octet_Info_Split_1), delai);
	HAL_UART_Transmit(huart, &Octet_Info_Split_2, sizeof(Octet_Info_Split_2), delai);

}

int getValue(ADC_HandleTypeDef* hadc)
{
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 100);
	int sensorValue = HAL_ADC_GetValue(&hadc);

	if (sensorValue < 2375)
	{
		sensorValue *= const1;
	}
	else {
		sensorValue = 0.6 + (sensorValue-2375)*const2;
	}

	return 100*sensorValue;
}

int isAck(uint8_t NumCapteur, uint8_t TypeDonnee, uint8_t OctetRecu) {
    return ((OctetRecu >> 4) == NumCapteur) && (((OctetRecu >> 1) & 0x7) == TypeDonnee) && ((OctetRecu & 1) == 1);
}
