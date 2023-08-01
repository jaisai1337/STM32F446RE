#include "../STM32F446RE/stm32f4xx.h"
#include <stdio.h>

#define GPIOAEN						(1U<<0)
#define PIN5						(1U<<5)
#define LED_PIN						PIN5

int main(void){
	RCC->AHB1ENR |=GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
	while(1){
		GPIOA->BSRR=LED_PIN;

		//idk why this is not working so imma just do this print statement
		for(int i=0;i<10000;i++){
			printf("Hello from STM32F446RE!\n\r");
		}
		GPIOA->BSRR=(1U<<21);
		for(int i=0;i<10000000;i++);
	}
}

