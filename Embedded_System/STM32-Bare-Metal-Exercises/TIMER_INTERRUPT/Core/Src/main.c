#include <stdio.h>
#include "stm32c0xx.h"

volatile uint8_t trigger_n;

void setup (void) {

	RCC -> IOPENR |= (1 << 0); //PA OPEN
	RCC -> APBENR1 |= (1 << 1); //TIM3 OPEN


	GPIOA -> MODER &= ~(1 << 1); //PA0 OUTPUT - REDLED

	//TIMER

	TIM3 -> CNT = 0; //TIME RESET
	TIM3 -> PSC = 11999; //CONFİG FREQUENCY
	TIM3 -> ARR = 1000; //TARGET TIME
	TIM3 -> CR1 |= (1 << 0);

	//TIMER-INTERRUPT

	TIM3 -> DIER |= (1 << 0); //TIMER INTERRUPT ENABLE
	NVIC_EnableIRQ(TIM3_IRQn); //NVI TIMER INTERRUPT ENABLE

}

void TIM3_IRQHandler(void) {

	if (TIM3 -> SR & (1 << 0)) {

		trigger_n = 1;

	}

	TIM3 -> SR &= ~(1 << 0); //RESET FLAG
}

int main (void) {

	setup();

	while(1) {
		if (trigger_n == 1) {

				GPIOA -> ODR ^= (1 << 0); //TOGGLE
				trigger_n = 0;
			}
	}
}
