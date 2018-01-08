/* эта штука работает, но ОС распознает как устройство вывода, а не ввода */

#include <MIDI.h>
#define NUM_BUTTONS 4

MIDI_CREATE_DEFAULT_INSTANCE(); 

const uint8_t button1 = 4;
const uint8_t button2 = 5;
const uint8_t button3 = 6;
const uint8_t button4 = 7;

byte rowPins[NUM_BUTTONS] = { 4, 5, 6, 7 }; // Пины кнопок

//Массив состояния кнопок
byte buttonState[NUM_BUTTONS] = { 1, 1, 1, 1 };

//Массив нот
byte kpdNote[NUM_BUTTONS] = {60, 64, 68, 71};

byte dval = 0;

void setup() {
  // put your setup code here, to run once:
   MIDI.begin(1);  //Инициализация MIDI интерфейса

  pinMode(13, OUTPUT);//--Гасим встроенный светодиод--
  digitalWrite(13, LOW);//----------------------------

  for(byte i = 0; i < NUM_BUTTONS; i++){      //--Конфигурируем столбцы мтрчн клвтр как входы--------- 
    pinMode(rowPins[i], INPUT);      //--и включаем встроенные в мк подтягивающие резисторы--
    digitalWrite(rowPins[i], HIGH);  //------------------------------------------------------
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  for(byte j = 0; j < NUM_BUTTONS; j++){
    //--Построчно считываем каждый столбец--
    //--И при нажатой кнопке передаём ноту--
    dval=digitalRead(rowPins[j]);
    if ( dval == LOW && buttonState[j] == HIGH ) MIDI.sendNoteOn(kpdNote[j],127,1); 
    if ( dval == HIGH && buttonState[j] == LOW ) MIDI.sendNoteOff(kpdNote[j],127,1);
    buttonState[j] = dval;
  }  

}
