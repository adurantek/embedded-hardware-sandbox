void setup() {
RCC -> IOPENR |= (1 << 0);
RCC -> IOPENR |= (1 << 2);
GPIOC -> MODER &= ~((1 << 26) | (1 << 27));
GPIOA -> MODER &= ~(1 << 11);
GPIOA -> MODER |= (1 << 10);
GPIOC -> PUPDR |= (1 << 26);
GPIOC -> PUPDR &= ~(1 << 27);
}

void loop() {
if((GPIOC -> IDR & (1 << 13)) == 0) {
GPIOA -> BSRR = (1 << 5);
}
else {
GPIOA -> BSRR = (1 << 21);
}
}