/* RGB светодиод */

int b = 11;
int g = 12;
int r = 13;




void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(r, HIGH); //включаем красный
  delay(500); //ждем 500 Мс
  digitalWrite(r, LOW); //выключаем красный
  digitalWrite(g, HIGH); //включаем зеленый
  delay(500); //ждем 500 Мс
  digitalWrite(g, LOW); //выключаем зеленый
  digitalWrite(b, HIGH); //включаем синий
  delay(500); //ждем 500 Мс
  digitalWrite(b, LOW); //выключаем синий
}
