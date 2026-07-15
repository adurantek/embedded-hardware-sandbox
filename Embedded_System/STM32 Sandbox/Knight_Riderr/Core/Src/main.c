#include "stm32c0xx.h"
#include <stdint.h>

void setup(void) {
	RCC -> IOPENR |= (1 << 0); //ENABLE PORTA

	RCC -> APBENR1 |= (1 << 1); //ENABLE PERİPHERAL OF THE TIMER3

	GPIOA -> MODER &= ~((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9) | (1 << 11)); //01 output PIN012345 -Bits are set to 0-

	GPIOA -> MODER &= ~((1 << 12) | (1 << 13) | (1 << 14) | (1 << 15)); //00 input PIN6 BUTTON1 PIN7 BUTTON2 -Bits are set to 0-

	//PULL-UP

	GPIOA -> PUPDR |= ((1 << 12) | (1 << 14)); //01 pull-up BUTTONS -Bits are set to 1-

	// INTERRUPT 1 PIN6

	EXTI -> EXTICR[1] |= (0x00 << 16); //ENABLE PORT

	EXTI -> FTSR1 |= (1 << 6); //ENABLE FALLING

	EXTI -> IMR1 |= (1 << 6); //ENABLE MASK

	// INTERRUPT 2 PIN7

	EXTI -> EXTICR[1] |= (0x00 << 24); //ENABLE PORT

	EXTI -> FTSR1 |= (1 << 7); //ENABLE FALLING

	EXTI -> IMR1 |= (1 << 7); //ENABLE MASK

	NVIC_EnableIRQ(EXTI4_15_IRQn); //ALLOW AND FINISH

}

	//TIMER FUNCTION

void mydelay(uint16_t ms) {

		TIM3 -> CR1 &= ~(1 << 0);     // 1. Önce kronometreyi durdur (Ne olur ne olmaz)
		TIM3 -> CNT = 0; //RESET TIME
		TIM3 -> PSC = 47999; //CONFİG FREQUENCY
		TIM3 -> ARR = ms; //TARGET VALUE
		TIM3 -> EGR |= (1 << 0); // 4. SİHİRLİ DOKUNUŞ: Değerleri gölge register'lardan asıl register'lara ZORLA yükle!
		// 5. EGR'yi 1 yapınca donanım "Süre doldu" sanıp SR bayrağını kaldırır.
		// Başlamadan önce o sahte bayrağı temizlemeliyiz!
		TIM3 -> SR &= ~(1 << 0);

		TIM3 -> CR1 |= (1 << 0); //KRONOMETER OPEN

		while((TIM3 -> SR1 & (1 << 0)) == 0 /*FLAG CONTROL*/) {};

		TIM3 -> CR1 &= ~(1 << 0); //KRONOMETER OFF

		TIM3 -> SR &= ~(1 << 0); //FLAG RESET
	}

void EXTI4_15_IRQHandler(void) {

	if (EXTI -> FPR1 & (1 << 6)) {

		GPIOA -> BSRR = ((1 << 0)| (1 << 20)); //RED LED1 ON AND GREEN LED1 OFF
		mydelay(1000);
		GPIOA -> BSRR = ((1 << 1) | (1 << 21)); //RED LED2 ON AND GREEN LED2 OFF
		mydelay(1000);
		GPIOA -> BSRR = ((1 << 2) | (1 << 16)); //YELLOW LED1 ON AND RED LED1 OFF
		mydelay(1000);
		GPIOA -> BSRR = ((1 << 3) | (1 << 17)); //YELLOW LED2 ON AND RED LED2 OFF
		mydelay(1000);
		GPIOA -> BSRR = ((1 << 4) | (1 << 18)); //GREEN LED1 ON AND YELLOW LED1 OFF
		mydelay(1000);
		GPIOA -> BSRR = ((1 << 5) | (1 << 19)); //GREEN LED2 ON AND YELLOW LED2 OFF
		mydelay(1000);

		EXTI -> FPR1 |= (1 << 6); //OFF INTERRUPT REDBUTTON
	}

	if (EXTI -> FPR1 & (1 << 7)) {

		GPIOA -> BSRR = ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)); // ALL LEDS ON
		mydelay(2000);
		GPIOA -> BSRR = ((1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20) | (1 << 21)); // ALL LEDS ON
		mydelay(2000);

		EXTI -> FPR1 |= (1 << 7); //OFF INTERRUPT GREENBUTTON
		}
}

int main(void) {
	setup();
	GPIOA -> BSRR = ((1 << 0) | (1 << 1) | (1 << 20) | (1 << 21)); //REDLEDS ON
	mydelay(500);
	GPIOA -> BSRR = ((1 << 2) | (1 << 3) | (1 << 16) | (1 << 17)); //YELLOW LEDS ON
	mydelay(500);
	GPIOA -> BSRR = ((1 << 4) | (1 << 5) | (1 << 18) | (1 << 19)); //GREEN LEDS ON
	mydelay(500);
	while(1) {

	}
}
