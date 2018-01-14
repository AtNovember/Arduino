#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  // lcd.clear(); // очистка дисплея
  lcd.print("ABCDEFJHIGKLMNOPST");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
