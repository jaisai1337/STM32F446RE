#include <stdio.h>
#include "stdint.h"
#include "stm32f4xx.h"
#include "uart.h"
#include "systick.h"

int key=0;
int main(void){
	
	uart2_rxtx_init();
	while(1){
		for (int i=1; i<=10; i++){
			printf("%d Hello World!\n\r", i);
			systickDelayMs(1000);
			key++;
		}
		break;
	}
}