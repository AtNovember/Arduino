/* joystick + servo */

#include <Servo.h> //используем библиотеку для работы с сервоприводом

Servo servo; //объявляем переменную servo типа Servo

// Arduino pin numbers
const int SW_pin = A5; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
//const int SW_pin = A5; // digital pin connected to switch output

void setup() {
  servo.attach(10); // привязываем привод к порту 10

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
//  servo.write(0); //ставим вал под 0
//  delay(1000); //ждем 2 секунды
//  servo.write(180); //ставим вал под 180
//  delay(1000); //ждем 2 секунды
//  servo.write(90); //ставим вал под 0  
  if (analogRead(Y_pin) >= 512) {
    servo.write(0); //ставим вал под 0  
//    delay(1000); //ждем 2 секунды
  } else {
    servo.write(180); //ставим вал под 180  
//    delay(1000); //ждем 2 секунды
  }
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  

//  delay(500);

}
