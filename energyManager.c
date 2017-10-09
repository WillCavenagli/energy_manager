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

#include <tm4c123gh6pm.h>
#include <inttypes.h>

//Variáveis Globais
uint32_t leituraLDR = 0; //até 4000+-
uint32_t perfilAtual = 0;

uint32_t frequencia = 16000;
uint32_t porcentagem = 1;
uint32_t dutyCycle = 0;

void delay(uint32_t valor)
{
    uint32_t count = 0;
    for (count = 0; count < valor; ++count)
        ;
}

//Métodos do display
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
    case 100:
        //00110101 - 5
        //01010111 - W
        //00101100 - ,

        GPIO_PORTE_DATA_R = 0b00001010; //5
        GPIO_PORTA_DATA_R = 0b00110100;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001110; //W
        GPIO_PORTA_DATA_R = 0b01010100;
        pulsoEnable();
        break;

    case 50:
        GPIO_PORTE_DATA_R = 0b00001100; //2
        GPIO_PORTA_DATA_R = 0b00110000;
        pulsoEnable();
        GPIO_PORTE_DATA_R = 0b00001110; //W
        GPIO_PORTA_DATA_R = 0b01010100;
        pulsoEnable();
        break;
    default:
        break;
    }

}

//Configuração geral dos ports
void configuraPorts()
{
    dutyCycle = (frequencia * porcentagem) / 100;

    SYSCTL_RCGCGPIO_R = 1 << 3 | 1 << 1 | 1 << 0 | 1 << 4; //Em ordem: PD, PB, PA e PE

    GPIO_PORTA_DIR_R = 0b11111100; // Output
    GPIO_PORTE_DIR_R = 0b00011110;

    GPIO_PORTA_DATA_R = 0;
    GPIO_PORTE_DATA_R = 0;

    GPIO_PORTA_DEN_R = 0b11111100;
    GPIO_PORTE_DEN_R = 0b00011110;

    SYSCTL_RCGCADC_R = 1; //ADC0

    //Configuração PortD - LDR
    GPIO_PORTD_AFSEL_R = 1 << 1; // Funcao alternativa em PD0
    GPIO_PORTD_AMSEL_R = 1 << 1; //Analog In em PD0

    //Configuração PWM para controle do Motor
    GPIO_PORTB_AFSEL_R = 1 << 6;
    GPIO_PORTB_PCTL_R = 1 << 26;
    GPIO_PORTB_DEN_R = 1 << 6; //PB6

    delay(200000);
    SYSCTL_RCGCPWM_R = 1;
    delay(200000);
    PWM0_0_GENA_R = 0xC8;
    delay(200000);
    PWM0_0_LOAD_R = frequencia;
    delay(200000);
    PWM0_0_CMPA_R = dutyCycle;
    delay(200000);
    PWM0_0_CTL_R = 1;
    delay(200000);
    PWM0_ENABLE_R = 1;
    delay(200000);

    //Configuração do ADC para leitura do LDR
    ADC0_ACTSS_R = 0;
    ADC0_EMUX_R = 15;
    ADC0_SSMUX0_R = 6; //6 - Equivalente ao PD1
    ADC0_SSCTL0_R = 2;
    ADC0_ACTSS_R = 1;
    ADC0_PSSI_R = 1;

    //Configurações iniciais para display
    inicializaDisplay();
    textoPerfil();
    textoPotencia();
    textoAdicionaNumPerfil(1);

    //Configuração Systick
    NVIC_ST_RELOAD_R = 40000; //10ms
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_INTEN;
}

void alteraPWM(uint32_t valor)
{
    porcentagem = valor;
    dutyCycle = (frequencia * porcentagem) / 100;
    delay(200000);
    PWM0_0_CMPA_R = dutyCycle;
    delay(200000);
}

void tratamentoSystick()
{
    //A cada 20ms o valor do LDR é verificado e a ação definida pelo perfil é tomada

    leituraLDR = ADC0_SSFIFO0_R;

    if (leituraLDR > 0 && leituraLDR <= 1920) //Entre 0% e 49%
    {
        alteraPWM(50); // 50% de PWM
        textoAdicionaValorPotencia(50);
    }
    else if (leituraLDR > 1920 && leituraLDR < 4200) //Entre 50% e 100%
    {
        alteraPWM(98); //
        textoAdicionaValorPotencia(100);
    }
}

int main(void)
{
    configuraPorts();

    while (1)
        __asm("WFI");
}
