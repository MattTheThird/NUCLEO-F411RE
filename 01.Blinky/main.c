#include "stm32f4xx.h"
void delayMs(int delay);

int main(void){
	RCC		->	AHB1ENR |= 1;						// Set RCC_AHB1ENR bit 1 to enable clock for GPIOA
	GPIOA	->	MODER 	|= 0x400;				// 010000000000
	while(1){
		GPIOA		->	ODR = 0x20;
		delayMs(100);
		GPIOA		->	ODR &=~0x20;
		delayMs(900);
	}
}

// This is for a 16 MHz system clock
void delayMs(int delay){
	int i;
	for(; delay>0; delay--){
		for(i=0;i<3195;i++);
	}
}

