#include "stm32f4xx.h"                  // Device header

void USART2_Init(void);
void USART_Write(int ch);
void delayMs(int delay);
	
int main(void){
	USART2_Init();
	
	while(1){
		USART_Write('H');
		USART_Write('i');
		USART_Write('\r');
		USART_Write('\n');
		delayMs(10);
	}
}

void USART2_Init(void){
	RCC->APB1ENR |= 1<<17;			// Enable system clock for USART2
	RCC->AHB1ENR |= 1;						// Enable system clock for GPIOA
	
	GPIOA->AFR[0] = 7<<8;				// GPIOA alternate function low register, bit 2, as AF7 (USART2_TX)
	GPIOA->MODER |= 2<<4;					// PA2 set as "Alternate function" mode
	
	USART2->BRR = 0x0683;				// 9600 @ 16 MHz system clock
	USART2->CR1 = 1<<3;					// Tx enable
	USART2->CR1 |= 1<<13;					// USART2 enable
}

void USART_Write(int ch){
	while(!(USART2->SR & 0x0080)){} // Wait for transmission buffer (TXE) to be empty ('1')
		USART2->DR = (ch & 0xFF);
}

void delayMs(int delay){
	int i;
	for (; delay>0; delay--)
		for (i=0; i<3195; i++);
}
