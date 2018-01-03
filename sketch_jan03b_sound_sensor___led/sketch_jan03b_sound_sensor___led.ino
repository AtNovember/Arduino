/* Микрофон */

int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor


 
void setup () 
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);

  if (sensorValue >= 100) {
    digitalWrite (ledPin, HIGH);
//    delay (sensorValue);
  } else {
    digitalWrite (ledPin, LOW);
  }
  
//  delay (sensorValue);
  Serial.println (sensorValue, DEC);
}
