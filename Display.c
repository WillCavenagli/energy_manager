#include <tm4c123gh6pm.h>
#include <inttypes.h>

uint32_t delay(uint32_t valor)
{
    uint32_t count = 0;
    for (count = 0; count < valor; count++)
        ;
    return 0;
}

uint32_t pulsoEnable()
{

    GPIO_PORTE_DATA_R ^= 0b00010000;
    GPIO_PORTE_DATA_R ^= 0b00010000;

    return 0;
}

uint32_t configuraPorts()
{
    SYSCTL_RCGCGPIO_R = 1 << 0 | 1 << 4; //PortA e PortE

    GPIO_PORTA_DIR_R = 0b11111100; // Output
    GPIO_PORTE_DIR_R = 0b00011110;

    GPIO_PORTA_DATA_R = 0;
    GPIO_PORTE_DATA_R = 0;

    GPIO_PORTA_DEN_R = 0b11111100;
    GPIO_PORTE_DEN_R = 0b00011110;

    return 0;
}

uint32_t inicializaDisplay()
{

    delay(80000); //20ms

    GPIO_PORTA_DATA_R = 0b00110000;
    GPIO_PORTE_DATA_R = 0;

    pulsoEnable();

    delay(80000); //10ms

    pulsoEnable();

    delay(80000); //300us

    pulsoEnable();

    //********* AJUSTA O MODO DE UTILIZAÇÃO DO DISPLAY *********

    GPIO_PORTA_DATA_R = 0b00110000; //N=0 (1 Linha) & F=0 (5x7)
    GPIO_PORTE_DATA_R = 0;

    pulsoEnable();

    //**********************************************************

    //*************** DESLIGA O DISPLAY ************************

    GPIO_PORTA_DATA_R = 0b00001000;
    GPIO_PORTE_DATA_R = 0;

    pulsoEnable();

    //***********************************************************

    //******************** LIMPA O DISPLAY **********************

    GPIO_PORTA_DATA_R = 0b00000000;
    GPIO_PORTE_DATA_R = 0b00000010;

    pulsoEnable();

    //***********************************************************

    //******** AJUSTA O MODO DE FUNCIONAMENTO DO CURSOR *********

    GPIO_PORTA_DATA_R = 0b00000100; //I-D=1 (Cursor p/ esquerda) & S=0 (Mensagem não desloca)
    GPIO_PORTE_DATA_R = 0b00000100;

    pulsoEnable();

    return 0;
}

/* Monstagem do display no Tiva
 *
 * PE1  -  DB0    Pino7 -
 * PE2  -  DB1    Pino8 -
 * PE3  -  RS     Pino4 -
 * PE4  -  E      Pino6 -
 *
 * PA2  -  DB2    Pino9 -
 * PA3  -  DB3    Pino10 -
 * PA4  -  DB4    Pino11 -
 * PA5  -  DB5    Pino12 -
 * PA6  -  DB6    Pino13 -
 * PA7  -  DB7    Pino14
 *
 */

int main(void)
{

    configuraPorts();

    inicializaDisplay();

    while (1)
    {
        __asm("WFI");
    }
    return 0;

}
