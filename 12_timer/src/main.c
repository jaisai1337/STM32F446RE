#include <stdio.h>
#include "stdint.h"
#include "stm32f4xx.h"
#include "uart.h"
#include "tim.h"

#define GPIOAEN             (1U<<0)
#define PA5                 (1U<<5)
#define LED_PIN             PA5
int key=0;
int main(void){
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	uart2_rxtx_init();
	tim2_1hz_init();
	while(1){
		for(int i=0; i<10; i++){
			while (!(TIM2->SR & SR_UIF));
			TIM2->SR &= ~SR_UIF;
			printf("A second has passed!\n\r");
			key++;
			GPIOA->ODR ^= LED_PIN;
		}
		break;
	}
}