#include <inttypes.h>
#include <tm4c123gh6pm.h>

/*
Lembrando que o elemento 0 do modulo PWM0 é o pino PB6, por isso se deve inicializar este pino em especifico para o funcionamento do elemento PWM
*/


int main(void) {

	//Ligar o PortB
	SYSCTL_RCGCGPIO_R = 1 << 1;
	//Habilitar função alternativa do PB6
	GPIO_PORTB_AFSEL_R = 1 << 6;
	//Definir que a função alternativa do PB6 é PWM
	GPIO_PORTB_PCTL_R = 1 << 26;
	//Habilita PB6 digitalmente
	GPIO_PORTB_DEN_R = 1 << 6;

	//Ativa o modulo de PWM 0
	SYSCTL_RCGCPWM_R = 1;
	//Nivel baixo em LOAD / Nivel alto em CMPA
	PWM0_0_GENA_R = 0xC8;
	//Valor de frequencia do PWM
	PWM0_0_LOAD_R = 32; // 16MHz/500Khz =
	//Valor de porcentagem do PWM
	PWM0_0_CMPA_R = (32 * 50) / 100; //50% Duty Cycle
	//Ativa o controle do elemento 0 do PWM0
	PWM0_0_CTL_R = 1;
	//Inicializa o PWM0
	PWM0_ENABLE_R = 1;

	while(1)
		__asm("WFI");
}
