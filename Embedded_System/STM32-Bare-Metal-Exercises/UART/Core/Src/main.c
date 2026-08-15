#include <stdio.h>
#include "stm32c0xx.h"
#include "stm32c031xx.h"

#define BRR_VALUE 0x4E2

char value;

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
  USART2->CR1 |= (1 << 5);                                          // Enable Interrupt for RX

  NVIC_EnableIRQ(USART2_IRQn);                                 // Enable USART2 interrupt in NVIC
}

void send_char(char c) {
  while((USART2->ISR & (1 << 7)) == 0);                             // Wait until TXE (Transmit Data Register Empty) flag is set
  USART2->TDR = c;                                                  // Transmit the character
}

void send_string(char *str) {
  while (*str != '\0') {
    send_char(*str);
    str++;
  }
}

void USART2_IRQHandler(void) {
  if ((USART2->ISR & (1 << 5)) != 0) {                                // Control
    value = USART2->RDR;                                              // Read the received character from the data register
    send_string("Word: ");
    send_char(value);
    send_string("\r\n");                                          // Echo the received character back
  }
}

int main(void) {
  setup();
  send_string("Click the button: \r\n");
  while (1);
}