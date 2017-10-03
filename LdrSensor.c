#include <tm4c123gh6pm.h>
#include <inttypes.h>

uint32_t leituraLDR = 0; //até 4000+-

SYSCTL_RCGCGPIO_R = 1 << 3; //PD
SYSCTL_RCGCADC_R = 1;//ADC0

GPIO_PORTA_DIR_R = 1 << 2; //PA2 para lED

GPIO_PORTA_DATA_R = 0;

GPIO_PORTA_DEN_R = 1 << 2;

GPIO_PORTD_AFSEL_R = 1; // Funcao alternativa em PD0

GPIO_PORTD_AMSEL_R = 1; //Analog In em PD0

ADC0_ACTSS_R = 0;
ADC0_EMUX_R = 15;
ADC0_SSMUX0_R = 7;//7 - Equivalente ao PD0
ADC0_SSCTL0_R = 2;
ADC0_ACTSS_R = 1;
ADC0_PSSI_R = 1;

while(1) {
    leituraLDR = ADC0_SSFIFO0_R;

    if (leituraLDR >= 3800) {
        GPIO_PORTA_DATA_R = 1 << 2;
    }else {
        GPIO_PORTA_DATA_R = 0;
    }
}
