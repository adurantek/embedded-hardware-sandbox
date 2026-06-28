#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define POTANT A0

LiquidCrystal_I2C lcd(0x27,16,2);

struct Valuables {
  unsigned long firstTime;
  int waitTime = 1000;
  unsigned long nowTime;
  unsigned long saniye;
  int degerP;
  int nemDegeri;
};

struct Valuables a;

void setup() {
  DDRC &= ~(0 << 0);
  lcd.init();
  lcd.backlight();
  }

void loop() {
  a.nowTime = millis();
  
  if (a.nowTime - a.firstTime >= a.waitTime) {
    a.firstTime = a.nowTime;
    a.degerP = analogRead(POTANT);
    a.nemDegeri = map(a.degerP,0,1023,0,100);
    a.saniye = a.nowTime/1000;
    String mesaj = "Saniye: " + String(a.saniye) + " s ";
    lcd.setCursor(0,0);
    lcd.print(mesaj);
    String mesaj1 = "Nemdegeri: %" + String(a.nemDegeri) + "  ";
    lcd.setCursor(0,1);
    lcd.print(mesaj1);
  
  }
}