#include "stm32f4xx.h"                  // Device header

int main(void){
	RCC->AHB1ENR |= 0x5;									// Enable system clock for GPIOA and GPIOC
	GPIOA->MODER |= 0x400;									// Establish PA5 as output (PC13 input by default)
	
	while(1){
		if(GPIOC->IDR & 0x2000){						// If bit PC13 is '1'
			GPIOA->BSRR = 1<<21;
		}
		else{
			GPIOA->BSRR = 1<<5;
		}
	}
}

