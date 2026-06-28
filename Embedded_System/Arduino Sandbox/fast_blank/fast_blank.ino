unsigned long oncekiZaman;
unsigned long beklemeSuresi = 500;

void setup() {
  DDRB |= (1 << 1);
}

void loop() {
  unsigned long simdikiZaman = millis();
  if (simdikiZaman - oncekiZaman >= beklemeSuresi) {
    oncekiZaman = simdikiZaman;
    PORTB ^= (1 << 1);
  }
}