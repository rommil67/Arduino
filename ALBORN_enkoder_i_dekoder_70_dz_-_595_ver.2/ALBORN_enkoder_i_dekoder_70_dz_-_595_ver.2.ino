#include <MIDI.h>   // Add Midi Library
int ledState = LOW;
int midi_channel = 1; // jesli ma dziłac na kanale 1
unsigned long currentMillis = 0;
unsigned long previousMillis = 0; 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
#define LiczbaKlawiszy (61)
boolean Key[LiczbaKlawiszy];
boolean Key2[LiczbaKlawiszy];
boolean Key3[LiczbaKlawiszy];
boolean Key4[LiczbaKlawiszy];
boolean Key5[LiczbaKlawiszy];

boolean Key_last[LiczbaKlawiszy];
boolean Key2_last[LiczbaKlawiszy];
boolean Key3_last[LiczbaKlawiszy];
boolean Key4_last[LiczbaKlawiszy];
boolean Key5_last[LiczbaKlawiszy];
int pin_data[] = {2,3,4,5,6,7,8,9}; // define data pins 
int vol = 90; // walue velocity
int channel_on = 0x90; // kanal 1 - initial variables for midi channel
int channel_off = 0x80; // kanal 1 - initial variables for midi channel
//Sterowanie zatrzaskiem 74HC595
//Pin connected to ST_CP of 74HC595
int latchPin = A1;
//Pin connected to SH_CP of 74HC595
int clockPin = A0;
////Pin connected to DS of 74HC595
int dataPin = 12;
int pin_adress0 = A0;
int pin_adress1 = A1;
int pin_adress2 = A2;
int pin_E1_man1 = A3;
int pin_E1_man2 = A4;


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
  MIDI.turnThruOff ();
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
  MIDI.setHandleControlChange(MyHandleControlChange);
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
   Key[i] = 1;
   Key2[i] = 1;
   Key3[i] = 1;
   Key4[i] = 1;
   Key5[i] = 1;
   Key_last[i] = 1;
   Key2_last[i] = 1;
   Key3_last[i] = 1;
   Key4_last[i] = 1;
   Key5_last[i] = 1;
   }
// define input pin_data
  for (int i = 0; i <= 7; i++) {
  pinMode(pin_data[i], INPUT_PULLUP);
  }
  
// define output LED
    pinMode(LED_BUILTIN, OUTPUT);
//define output pin_adress 74HC138) and 74HC 595
    pinMode(pin_adress0, OUTPUT);
    pinMode(pin_adress1, OUTPUT);
    pinMode(pin_adress2, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode( pin_E1_man1, OUTPUT);
    pinMode( pin_E1_man2, OUTPUT);
    
    digitalWrite(pin_adress0, HIGH);
    digitalWrite(pin_adress1, HIGH);
    digitalWrite(pin_adress2, HIGH);
    digitalWrite( pin_E1_man1, HIGH);
    digitalWrite(pin_adress2, HIGH);
    digitalWrite( pin_E1_man1, LOW);
    digitalWrite( pin_E1_man2, LOW);



/// Zerowanie zatrzasków
zatrzask_off();

}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
  sygnalizacja();
  //scaner();    
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


void scaner(){
     
   //*****************************************
 //Obsługa man II
 
digitalWrite( pin_E1_man1, HIGH); // A3
digitalWrite( pin_E1_man2, LOW); //A4

channel_on = 0x91; // ustawienie kanałów dla II man - kanal 2
channel_off = 0x81; // kanal 2

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 1-st (first) octet
      for (int i = 0; i <= 7; i++) {
      Key2[i+0*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 2-st (second) octet
      for (int i = 0; i <= 7; i++) {
      Key2[i+1*8] = digitalRead(pin_data[i]);
     }
  
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 3-st (thrid) octet
  
      for (int i = 0; i <= 7; i++) {
      Key2[i+2*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 4-st (quad) octet
  
   for (int i = 0; i <= 7; i++) {
      Key2[i+3*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 5-st (quad) octet
   for (int i = 0; i <= 7; i++) {
      Key2[i+4*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 6-st (qwint) octet
   for (int i = 0; i <= 7; i++) {
      Key2[i+5*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 7-st (sext) octet
   for (int i = 0; i <= 7; i++) {
      Key2[i+6*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 8-st (sept) octet
   for (int i = 0; i <= 7; i++) {
      Key2[i+7*8] = digitalRead(pin_data[i]);
     }
  
  

//****************************************************
// porównywanie odczytów i wysyłanie komunikatów midi dla man II
// 
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key2[i] != Key2_last[i] ) {
    if(Key2[i] == 0)  {
    //noteOn(channel_on, 36+i, vol);
     MIDI.sendNoteOn(36+i, 127, 2);
    }
    else  {
    //noteOn(channel_off, 36+i, 0x00);
    //noteOn(channel_off, 36+i, 0x00);
     MIDI.sendNoteOff(36+i, 0, 2);
     //MIDI.sendNoteOff(36+i, 0, 2);
  
    }
    }
    }
 
    
}

    void noteOn(byte cmd, byte data1, byte data2) {
   Serial.write(cmd);
   Serial.write(data1);
   Serial.write(data2);
      
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5);
  digitalWrite(LED_BUILTIN, LOW);

  
 
}

void sygnalizacja() {
  // moduł sygnalizacji działania 
 //----------------------------------------------------------
 currentMillis = millis();
 // szybkość działania programu
 // Serial.println(currentMillis);

  if (currentMillis - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN, ledState);
  }
}

void powrotdoustawien() {digitalWrite(pin_adress0, HIGH);
    digitalWrite(pin_adress1, HIGH);
    digitalWrite(pin_adress2, HIGH);
    digitalWrite( pin_E1_man1, HIGH);
    digitalWrite(pin_adress2, HIGH);
    digitalWrite( pin_E1_man1, LOW);
    digitalWrite( pin_E1_man2, LOW);
}
