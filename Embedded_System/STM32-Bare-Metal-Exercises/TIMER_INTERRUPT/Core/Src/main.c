#include <stdio.h>
#include "stm32c0xx.h"

uint8_t trigger_n;

void setup(void) {

	//TIMER-INTERRUPT

	TIM3 -> DMA |= (1 << 0); //TIMER INTERRUPT ENABLE
	NVIC_EnableIRQ(TIM3_IRQn); //NVI TIMER INTERRUPT ENABLE

}

void TIM3_IRQHandler(void) {
	trigger_n = 1;
	TIM3 -> SR &= ~(1 << 0);
}

void main (void) {

	while(1) {

	}
}
