#include <stdio.h>
#include "stdint.h"
#include "stm32f4xx.h"
#include "uart.h"


int main(void){
	uart2_tx_init();
	while(1){
		printf("Hello from STM32F446RE!\n\r");
		for(int i=0;i<10000000;i++);
	}
}