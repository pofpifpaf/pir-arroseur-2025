#include "Utility_Flash.h"

static FLASH_EraseInitTypeDef EraseInitStruct;



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t FirstSector = 0;
uint32_t NbOfSectors = 0;
uint32_t Address = 0;
uint32_t SECTORError = 0;
__IO uint32_t data32 = 0;
__IO uint32_t MemoryProgramStatus = 0;
/*Variable used for Erase procedure*/


static FLASH_EraseInitTypeDef EraseInitStruct;

/**
  * @brief  Gets the sector of a given address
  * @param  None
  * @retval The sector of a given address
  */
	
	
/**
  * @brief  Gets the sector of a given address
  * @param  None
  * @retval The sector of a given address
  */

static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_7) */
  {
    sector = FLASH_SECTOR_7;
  }
  return sector;
}

void Erase_Flash(void)
{

  /* Unlock the Flash to enable the flash control register access *************/
  HAL_FLASH_Unlock();
		
	
	 /* Erase the user Flash area
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  /* Get the 1st sector to erase */
  FirstSector = GetSector(FLASH_USER_START_ADDR);
  /* Get the number of sector to erase from 1st sector*/
  NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;
  /* Fill EraseInit structure*/
  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Sector        = FirstSector;
  EraseInitStruct.NbSectors     = NbOfSectors;

  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
  HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError);
  HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError);
	
  HAL_FLASH_Lock();
}

void Write_Word_Flash(uint32_t DestinationFlash, int N,int *Value32bits)
{
	uint32_t	Address_courante;
	
	HAL_FLASH_Unlock();
	
	Address_courante = DestinationFlash;
  
  while (Address_courante < DestinationFlash + N)
  {
  //  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address_courante, (uint32_t)(*Value32bits));
		Address_courante = Address_courante + 4;
		Value32bits ++;
		
  }
	HAL_FLASH_Lock();
}

void Write_Byte_Flash(uint32_t DestinationFlash, int N,char *Value8bits)
{
	uint32_t	Address_courante;
	
	HAL_FLASH_Unlock();
	
	Address_courante = DestinationFlash;
  
  while (Address_courante < DestinationFlash + N)
  {
  //  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, Address_courante, (uint32_t)(*Value8bits));
		Address_courante = Address_courante + 1;
		Value8bits ++;
		
  }
	HAL_FLASH_Lock();
}


void Read_Byte_Flash(uint32_t SourceFlash, int N, char *Value8bits)
{
	int Ind = 0;
	//HAL_FLASH_Unlock();
	
  
  while (Ind <  N)
  {
  //  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
		// HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, Address_courante, (uint32_t)(*Value32bits));
		*Value8bits = *((char*)SourceFlash);
		SourceFlash += 1;
		Value8bits += 1;
		Ind++;
		
  }
	//HAL_FLASH_Lock();
}

void Read_Word_Flash(uint32_t SourceFlash, int N, int *Value32bits)
{
	int Ind = 0;
	//HAL_FLASH_Unlock();
	
  
  while (Ind <  N)
  {
  //  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
		// HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, Address_courante, (uint32_t)(*Value32bits));
		*Value32bits = *((int *)SourceFlash);
		SourceFlash += 4;
		Value32bits += 1 ;
		Ind++;
		
  }
	//HAL_FLASH_Lock();
}
