#include "stm32c0xx.h"
#include <stdint.h>

volatile uint8_t leds_status = 0;

void setup(void) {
	RCC -> IOPENR |= (1 << 0); //ENABLE PORTA
	RCC -> APBENR1 |= (1 << 1); //ENABLE PERÄ°PHERAL OF THE TIMER3

	GPIOA -> MODER &= ~((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 9) | (1 << 11)); //01 output PIN012345
	GPIOA -> MODER &= ~((1 << 12) | (1 << 13) | (1 << 14) | (1 << 15)); //00 input PIN6 PIN7

	//PULL-UP

	GPIOA -> PUPDR |= ((1 << 12) | (1 << 14));

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

void mydelay(uint16_t ms) {

    TIM3 -> CNT = 0; //RESET TIME
    TIM3 -> PSC = 11999; //CONFIGURE FREQUENCY
    TIM3 -> ARR = ms; //TARGET TIME

    TIM3 -> SR &= ~(1 << 0); //TIMER CLOCK RESET
    TIM3 -> CR1 |= (1 << 0); //SET CLOCK

    while((TIM3->SR & (1 << 0)) == 0 /*STATUS CONTROL*/) {};

    TIM3 -> CR1 &= ~(1 << 0); //RESET CLOCK
    TIM3 -> SR &= ~(1 << 0); //RESET STATUS
}

void EXTI4_15_IRQHandler(void) {

	if (EXTI -> FPR1 & (1 << 6)) {

		leds_status = 1;

		EXTI -> FPR1 |= (1 << 6); //RESET
	}

	if (EXTI -> FPR1 & (1 << 7)) {

		leds_status = 2;

		EXTI -> FPR1 |= (1 << 7); //RESET
	}
}

int main(void) {

	setup();

	while(1) {

        if (leds_status == 0) {

            //START LEDS STATUS

        	GPIOA -> BSRR = ((1 << 0) | (1 << 1) | (1 << 20) | (1 << 21)); //RED LEDS OPEN AND GREEN LEDS CLOSE
            mydelay(100);
            GPIOA -> BSRR = ((1 << 2) | (1 << 3) | (1 << 16) | (1 << 17)); //YELLOW LEDS OPEN AND RED LEDS CLOSE
            mydelay(100);
            GPIOA -> BSRR = ((1 << 4) | (1 << 5) | (1 << 18) | (1 << 19)); //GREEN LEDS OPEN AND YELLOW LEDS CLOSE
            mydelay(100);
        }

        else if (leds_status == 1) {

            //REDBUTTON STATUS

        	GPIOA -> BSRR = ((1 << 0)| (1 << 20)); //REDLED1 OPEN AND GREENLED1 CLOSE
            mydelay(1000);
            GPIOA -> BSRR = ((1 << 1) | (1 << 21)); //REDLED2 OPEN AND GREENLED2 CLOSE
            mydelay(1000);
            GPIOA -> BSRR = ((1 << 2) | (1 << 16)); //YELLOWLED1 OPEN AND REDLED1 CLOSE
            mydelay(1000);
            GPIOA -> BSRR = ((1 << 3) | (1 << 17)); //YELLOWLED2 OPEN AND REDLED1 CLOSE
            mydelay(1000);
            GPIOA -> BSRR = ((1 << 4) | (1 << 18)); //GREENLED1 OPEN AND YELLOWLED1 CLOSE
            mydelay(1000);
            GPIOA -> BSRR = ((1 << 5) | (1 << 19)); //GREENLED2 OPEN AND YELLOWLED2 CLOSE
            mydelay(1000);
        }

        else if (leds_status == 2) {

        	//YELLOWBUTTON STATUS

        	GPIOA -> BSRR = ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)); //ALL LEDS OPEN
            mydelay(2000);
            GPIOA -> BSRR = ((1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20) | (1 << 21)); //ALL LEDS CLOSE
            mydelay(2000);
        }
	}
}
