#include <tm4c123gh6pm.h>
#include <inttypes.h>

int main(void){

  SYSCTL_RCGCUART_R = 1 << 1; //Modulo 1

  SYSCTL_RCGCGPIO_R = 1 << 1; //Port B

  GPIO_PORTB_AFSEL_R = 1 | 1 << 1; // PB0 e PB1

  GPIO_PORTB_PCTL_R = 0x22; // 0010 0010 - Define as funcões alternativas como:
                            //             Rx para PB0
                            //             Tx para PB1

  return 0;
}
