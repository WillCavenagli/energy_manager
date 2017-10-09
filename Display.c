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
    delay(10000);
    GPIO_PORTE_DATA_R ^= 0b00010000;
    delay(10000);
    GPIO_PORTE_DATA_R ^= 0b00010000;
    delay(10000);
    return 0;
}

void limpaDisplay()
{
    delay(10000);
    GPIO_PORTE_DATA_R = 0b00000010;
    GPIO_PORTA_DATA_R = 0b00000000;
    pulsoEnable();
}

void textoPerfil()
{
    delay(10000);
    GPIO_PORTE_DATA_R = 0;
    GPIO_PORTA_DATA_R = 0b00001100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00000100;
    GPIO_PORTA_DATA_R = 0b00001100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00000010;
    GPIO_PORTA_DATA_R = 0b00001100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00000100;
    GPIO_PORTA_DATA_R = 0b00000100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001000; //P
    GPIO_PORTA_DATA_R = 0b01010000;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001010; //E
    GPIO_PORTA_DATA_R = 0b01000100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001100; //R
    GPIO_PORTA_DATA_R = 0b01010000;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001100; //F
    GPIO_PORTA_DATA_R = 0b01000100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001010; //I
    GPIO_PORTA_DATA_R = 0b01001000;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001000; //L
    GPIO_PORTA_DATA_R = 0b01001100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001100; //:
    GPIO_PORTA_DATA_R = 0b00111000;
    pulsoEnable();
}

void textoPotencia()
{
    delay(10000);
    GPIO_PORTE_DATA_R = 0b00000000; //Posiciona na segunda linha
    GPIO_PORTA_DATA_R = 0b11000000;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001000; //P
    GPIO_PORTA_DATA_R = 0b01010000;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001110; //O
    GPIO_PORTA_DATA_R = 0b01001100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001000; //T
    GPIO_PORTA_DATA_R = 0b01010100;
    pulsoEnable();
    GPIO_PORTE_DATA_R = 0b00001100; //:
    GPIO_PORTA_DATA_R = 0b00111000;
    pulsoEnable();
}

void textoAdicionaNumPerfil(uint32_t valor)
{
    delay(10000);
    GPIO_PORTE_DATA_R = 0b00000000; //Posiciona no local
    GPIO_PORTA_DATA_R = 0b10001000;
    pulsoEnable();

    switch (valor)
    {
    case 1:
        GPIO_PORTE_DATA_R = 0b00001000; //0
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001010; //1
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        break;

    case 2:
        GPIO_PORTE_DATA_R = 0b00001000; //0
        GPIO_PORTA_DATA_R = 0b01110000;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001100; //2
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        break;
    default:
        break;
    }

}

void textoAdicionaValorPotencia(uint32_t valor)
{
    delay(10000);
    GPIO_PORTE_DATA_R = 0b00000010; //Posiciona no local
    GPIO_PORTA_DATA_R = 0b11000100;
    pulsoEnable();

    switch (valor)
    {
    case 1:
        GPIO_PORTE_DATA_R = 0b00001000; //0
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001010; //1
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        break;

    case 2:
        GPIO_PORTE_DATA_R = 0b00001000; //0
        GPIO_PORTA_DATA_R = 0b01110000;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001100; //2
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        break;
    default:
        break;
    }

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
    delay(1000000); //

    GPIO_PORTA_DATA_R = 0b00110000;
    delay(10000);
    GPIO_PORTE_DATA_R = 0;

    delay(10000);
    pulsoEnable();

    delay(1000000); //

    pulsoEnable();

    delay(1000000); //

    pulsoEnable();

    //********* AJUSTA O MODO DE UTILIZAÇÃO DO DISPLAY *********

    delay(10000);
    GPIO_PORTA_DATA_R = 0b00111000; //N=0 (1 Linha) & F=0 (5x7)
    delay(10000);
    GPIO_PORTE_DATA_R = 0;

    delay(10000);
    pulsoEnable();

    //**********************************************************

    //*************** DESLIGA O DISPLAY ************************

    delay(10000);
    GPIO_PORTA_DATA_R = 0b00001000;
    delay(10000);
    GPIO_PORTE_DATA_R = 0;

    delay(10000);
    pulsoEnable();

    //***********************************************************

    //******************** LIMPA O DISPLAY **********************

    delay(10000);
    GPIO_PORTA_DATA_R = 0b00000000;
    GPIO_PORTE_DATA_R = 0b00000010;

    delay(10000);
    pulsoEnable();

    //***********************************************************

    //******** AJUSTA O MODO DE FUNCIONAMENTO DO CURSOR *********

    delay(10000);
    GPIO_PORTA_DATA_R = 0b00000100; //I-D=1 (Cursor p/ esquerda) & S=0 (Mensagem não desloca)
    delay(10000);
    GPIO_PORTE_DATA_R = 0b00000100;
    delay(10000);

    pulsoEnable();

    return 0;
}

/* Montagem do display no Tiva
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

    limpaDisplay();
    textoPerfil();
    textoPotencia();
    textoAdicionaNumPerfil(1);
    while (1)
    {
        __asm("WFI");
    }
    return 0;

}
