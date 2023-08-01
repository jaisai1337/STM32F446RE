#include <stdint.h>

#define PERIPH_BASE					(0x40000000UL)
#define AHB1PERIPH_OFFSET 			(0x00020000UL)
#define AHB1PERIPH_BASE				(PERIPH_BASE + AHB1PERIPH_OFFSET) //40020000UL
#define GPIOA_OFFSET				(0x00000U)
#define GPIOA_BASE					(AHB1PERIPH_BASE + GPIOA_OFFSET) //40020000UL
#define RCC_OFFSET					(0x3800UL)
#define RCC_BASE					(AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN						(1U<<0)
#define PIN5						(1U<<5)
#define LED_PIN						PIN5

#define __IO 						volatile

typedef struct{
	__IO uint32_t DUMMY[12]; 	//0x00-0x2C
	__IO uint32_t AHB1ENR; 		//0x30
}RCC_TypeDef;

typedef struct{
	__IO uint32_t MODER; 	//0x00
	__IO uint32_t OTYPER; 	//0x04
	__IO uint32_t OSPEEDR;	//0x08
	__IO uint32_t PUPDR; 	//0x0C
	__IO uint32_t IDR;		//0x10
	__IO uint32_t ODR;		//0x14
	__IO uint32_t BSRR;		//0x18
	__IO uint32_t LCKR;		//0x1C
	__IO uint32_t AFR[2];	//0x20-0x24
}GPIO_TypeDef; //40020000UL


#define RCC 	((RCC_TypeDef*) RCC_BASE)
#define GPIOA 	((GPIO_TypeDef*) GPIOA_BASE)

int main(){
	//RCC_AHB1EN_R |= GPIOAEN;
	RCC->AHB1ENR |=GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
	while(1){
		//GPIOA_OD_R |=LED_PIN;
		GPIOA->ODR^=LED_PIN;
		for(int i=0;i<10000000;i++);
	}
}

