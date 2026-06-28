#define KIRMIZI_LED 8
#define YESIL_LED 9
#define BUTTON 2
volatile int systemState = 0;
void setup() {
  pinMode(KIRMIZI_LED, OUTPUT);
  pinMode(YESIL_LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), modDegistir, FALLING);
}

void loop() {
    switch (systemState) {
      case 0:
        digitalWrite(YESIL_LED, LOW);
        break;
      case 1:
        digitalWrite(KIRMIZI_LED, HIGH);
        break;
      case 2:
        digitalWrite(KIRMIZI_LED, LOW);
        digitalWrite(YESIL_LED, HIGH);
        break;
  }
}

void modDegistir () {
  systemState++;
  if (systemState > 2) {
    systemState = 0;
  }
  }