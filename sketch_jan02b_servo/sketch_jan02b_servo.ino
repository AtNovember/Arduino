#include <Servo.h> //используем библиотеку для работы с сервоприводом

Servo servo; //объявляем переменную servo типа Servo

// процедура setup

void setup() {
  servo.attach(10); //привязываем привод к порту 10
}

// процедура loop

void loop() {
  servo.write(0); //ставим вал под 0
  delay(1000); //ждем 2 секунды
  servo.write(180); //ставим вал под 180
  delay(1000); //ждем 2 секунды
}
