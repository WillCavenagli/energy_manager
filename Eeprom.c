#include <tm4c123gh6pm.h>
#include <inttypes.h>

#define EEPROM_INIT_OK 0
#define EEPROM_INIT_ERROR 2

uint32_t EInit(void) //Inicializa a EEPROM para gravação de dados
{
    uint32_t ui32Aux;
    SYSCTL_RCGCEEPROM_R = 1;
    for(ui32Aux=0;ui32Aux<2;ui32Aux++){}
    while(EEPROM_EEDONE_WORKING){}
    if(EEPROM_EESUPP_R == 8 || EEPROM_EESUPP_R == 4)
    {
        return(EEPROM_INIT_ERROR);
    }

    SYSCTL_SREEPROM_R = 1;
    SYSCTL_SREEPROM_R = 0;
    for(ui32Aux=0;ui32Aux<2;ui32Aux++){}
    while(EEPROM_EEDONE_WORKING){}
    if(EEPROM_EESUPP_R == 8 || EEPROM_EESUPP_R == 4)
    {
    	return(EEPROM_INIT_ERROR);
    }

    return(EEPROM_INIT_OK);

}

void main()
{
	if(EInit()==0){
		while(1){
			//Código de acesso aqui

      //OFFSET
      //BLOCK
      //RW
		}
	}
}
