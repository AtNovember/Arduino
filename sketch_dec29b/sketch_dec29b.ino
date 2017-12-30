/*
  Затухающий светодиод
*/

int led = 9; // пин, к которому подключен светодиод, если подключить в 8 работать не будет
int brightness = 0; // яркость светодиода
int fadeAmount = 5; // на сколько увеличить яркость светодиода


void setup() {
  // объявляет 9 пин в качестве выхода:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;
  
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  
  delay(30);
}
