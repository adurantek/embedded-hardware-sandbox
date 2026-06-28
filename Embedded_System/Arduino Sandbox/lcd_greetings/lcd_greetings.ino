#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdScreen(0x27,16,2);
void setup() {
  lcdScreen.init();
  lcdScreen.backlight();
  lcdScreen.setCursor(0,0);
  lcdScreen.print("-Are you here?");
  lcdScreen.setCursor(0,1);
  lcdScreen.print("+Yes!");
}

void loop() {
}