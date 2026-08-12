#include <stdio.h>
#include "stm32c0xx.h"
#include "stm32c031xx.h"

#define BRR_VALUE 0x4E2

void delay(uint8_t ms) {
  for (volatile int i = 0; i < ms * 1000; i++); // Simple delay loop
}

void setup(void) {
  RCC->IOPENR |= (1 << 0);                                          // Enable GPIOA clock
  RCC->APBENR1 |= (1 << 17);                                        // Enable USART2 clock
  GPIOA->MODER &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));     // Clear PA2 (TX) and PA3 (RX) mode bits
  GPIOA->MODER |= ((1 << 5) | (1 << 7));                            // Set Alternate Function for PA2 and PA3 mode bits
  GPIOA->AFR[0] &= ~(0b11111111 << 8);                              // Clear PA2 and PA3 alternate function bits
  GPIOA->AFR[0] |= ((1 << 8) | (1 << 12));                          // Set PA2 and PA3 alternate function to AF1 (USART2)
  USART2->BRR = BRR_VALUE;                                          // Set baud rate to 9600
  USART2->CR1 |= (1 << 3);                                          // Enable USART2 transmitter
  USART2->CR1 |= (1 << 2);                                          // Enable USART2 receiver
  USART2->CR1 |= (1 << 0);                                          // Enable USART2
}

void send_char(char c) {
  while((USART2->ISR & (1 << 7)) == 0);                             // Wait until TXE (Transmit Data Register Empty) flag is set
  USART2->TDR = c;                                                  // Transmit the character
}

int main(void) {
  setup();
  while (1) {
    send_char('H');
    send_char('e');
    send_char('l');
    send_char('l');
    send_char('o');
    delay(243); // Delay for 243 ms
    send_char('\n');
  }
}