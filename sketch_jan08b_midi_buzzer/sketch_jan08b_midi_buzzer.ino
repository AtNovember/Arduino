#include <SoftwareSerial.h>

#include <MIDI.h>
#include <midi_defs.h>
#include <midi_message.h>
#include <midi_namespace.h>
#include <midi_settings.h>

const int buzzer = 9; //buzzer to arduino pin 9
const int buttonOne = 4; // assign button pin to variable
const int buttonTwo = 5; // assign button pin to variable

MIDI_CREATE_INSTANCE(HardwareSerial,Serial, midiOut); // create a MIDI object called midiOut

void setup() {
//  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

  pinMode(buttonOne,INPUT); // setup button as input
  pinMode(buttonTwo,INPUT); // setup button as input
  Serial.begin(31250); // setup MIDI output
}

void loop() {
  if(digitalRead(buttonOne) == HIGH) { // check button state
    delay(10); // software de-bounce
    if(digitalRead(buttonOne) == HIGH) { // check button state again
      midiOut.sendControlChange(56,127,1); // send a MIDI CC -- 56 = note, 127 = velocity, 1 = channel
      delay(250); 
    }
  }
 
  if(digitalRead(buttonTwo) == HIGH) { // check button state
    delay(10); // software de-bounce
    if(digitalRead(buttonTwo) == HIGH) { // check button state again
      midiOut.sendControlChange(42,127,1); // send a MIDI CC -- 42 = note, 127 = velocity, 1 = channel
      delay(250);
    }
  }
}
