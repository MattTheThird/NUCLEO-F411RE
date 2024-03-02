#include "stm32f4xx.h"                  // Device header

void delayMs(int delay);

int main(void){
	RCC -> AHB1ENR |= 1;
	GPIOA->MODER |= 0x400;
	while(1){
		GPIOA -> BSRR = 0x20;								// Set PA5
		delayMs(100);
		GPIOA -> BSRR = 0x00200000;						// Reset PA5
		delayMs(100);
	}	
}

void delayMs(int delay){
	int i;
	for(; delay>0; delay--){
		for(i=0; i<3195;i++);
	}
}

