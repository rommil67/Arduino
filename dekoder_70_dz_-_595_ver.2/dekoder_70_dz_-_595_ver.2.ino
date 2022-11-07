#include <MIDI.h>   // Add Midi Library
 
int midi_channel = 16; // jesli ma dziłac na kanale 1
 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

//Sterowanie zatrzaskiem 74HC595
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

byte g = 0;
byte h = 0;
byte j = 0;
byte k = 0;
byte l = 0;
byte m = 0;
byte n = 0;
byte o = 0;
byte p = 0;
 
void setup() {

  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
  MIDI.setHandleControlChange(MyHandleControlChange);
  
 // inicjalizacja pinów od zatrzasku
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
/// Zerowanie zatrzasków
zatrzask_off();

}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}

//+++++++ Włączenie nuty+++++++
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
    if (channel == midi_channel) {
      if (pitch > 35 and pitch < 44) {
        bitSet(g, pitch - 36);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
         if (pitch > 43 and pitch < 52) {
        bitSet(h, pitch - 44);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 51 and pitch < 60) {
        bitSet(j, pitch - 52);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 59 and pitch < 68) {
        bitSet(k, pitch - 60);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 67 and pitch < 76) {
       bitSet(l, pitch - 68);
       zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 75 and pitch < 84) {
        bitSet(m, pitch - 76);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 83 and pitch < 92) {
        bitSet(n, pitch - 84);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 91 and pitch < 100) {
        bitSet(o, pitch - 92);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 99 and pitch < 108) {
        bitSet(p, pitch - 100);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    }
    }


  
  
    
   

 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
    if (channel == midi_channel) {
      if (pitch > 35 and pitch < 44) {
        bitClear(g, pitch - 36);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
         if (pitch > 43 and pitch < 52) {
        bitClear(h, pitch - 44);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 51 and pitch < 60) {
        bitClear(j, pitch - 52);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 59 and pitch < 68) {
        bitClear(k, pitch - 60);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 67 and pitch < 76) {
       bitClear(l, pitch - 68);
       zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 75 and pitch < 84) {
        bitClear(m, pitch - 76);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 83 and pitch < 92) {
        bitClear(n, pitch - 84);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 91 and pitch < 100) {
        bitClear(o, pitch - 92);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    if (pitch > 99 and pitch < 108) {
        bitClear(p, pitch - 100);
        zapiszdo595(g, h, j, k, l, m, n, o, p);
    }
    }
    }
  
  
void MyHandleControlChange(byte channel, byte number, byte value){
  if (number == 120) {
   zatrzask_off(); 
  }
  if (number == 123) {
   zatrzask_off(); 
  }
delay(300);
}

void zapiszdo595(byte q1,byte q2, byte q3, byte q4, byte q5, byte q6, byte q7, byte q8, byte q9 ) {
 
digitalWrite(latchPin, LOW);

shiftOut(dataPin, clockPin, MSBFIRST, q9);
shiftOut(dataPin, clockPin, MSBFIRST, q8);
shiftOut(dataPin, clockPin, MSBFIRST, q7);
shiftOut(dataPin, clockPin, MSBFIRST, q6);
shiftOut(dataPin, clockPin, MSBFIRST, q5);
shiftOut(dataPin, clockPin, MSBFIRST, q4);
shiftOut(dataPin, clockPin, MSBFIRST, q3);
shiftOut(dataPin, clockPin, MSBFIRST, q2);
shiftOut(dataPin, clockPin, MSBFIRST, q1);


digitalWrite(latchPin, HIGH);  
}

void zatrzask_off(){
g=0;
h=0;      
j=0;
k=0;
l=0;
m=0;
n=0;
o=0;
p=0;
   zapiszdo595(g, h, j, k, l, m, n, o, p);
}
