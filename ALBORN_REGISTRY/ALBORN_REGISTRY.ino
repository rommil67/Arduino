#include <MIDI.h>   // Add Midi Library
//---------------------------------------------------------------------------
//----------------------------for signalisations work:----------------------
// Variables will chang
int ledState = LOW;             // ledState used to set the LED
int midi_channel = 1; // jesli ma dziłac na kanale 1
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000; 
//-------------------------------------------------------
MIDI_CREATE_DEFAULT_INSTANCE();
// define adress pins for adressed 74HC138
#define LED_BUILTIN_A4 A4
#define pin_adress0 10 //A0
#define pin_adress1 12 //A1
#define pin_adress2 A0 //A2
#define pin_E1_man1 A2 //A3
#define pin_E1_man2 8  //A4
#define pin_E1_man3 A5
#define pin_E1_man4 6 // 10
#define pin_E1_man5 2 //11

//Pin connected to ST_CP of 74HC595
#define latchPin  12 //A1
//Pin connected to SH_CP of 74HC595
#define clockPin  10 //A0
////Pin connected to DS of 74HC595
#define dataPin  4 //12

byte g = 0;
byte h = 0;
byte j = 0;
byte k = 0;
byte l = 0;
byte m = 0;
byte n = 0;
byte o = 0;
byte p = 0;

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
int pin_data[] = {3,5,7,9,11,13,A1,A3}; // define data pins
//int pin_data[] = {A3,A1,13,11,9,7,5,3}; // define data pins
//int pin_data[] = {2,3,4,5,6,7,8,9}; // define data pins

 


int vol = 90; // walue velocity
int channel_on = 0x90; // kanal 1 - initial variables for midi channel
int channel_off = 0x80; // kanal 1 - initial variables for midi channel

// int channel_on = 0x91; // kanal 2
// int channel_off = 0x81; // kanal 2

// int channel_on = 0x92; // kanal 3
// int channel_off = 0x81; // kanal 3

//int channel_on = 0x93; // kanal 4
//int channel_off = 0x83; // kanal 4

// int channel_on = 0x94; // kanal 5
// int channel_off = 0x84; // kanal 5

// int channel_on = 0x95; // kanal 6
// int channel_off = 0x85; // kanal 6

// int channel_on = 0x96; // kanal 7
// int channel_off = 0x86; // kanal 7

// int channel_on = 0x97; // kanal 8
// int channel_off = 0x87; // kanal 8

void setup()  {
   MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  MIDI.turnThruOff ();
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
//  MIDI.setHandleControlChange(MyHandleControlChange);
 
  Serial.begin (31250); //(31250); // setup serial for MIDI
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
 
  //define output pin_adress 74HC138)
    pinMode(pin_adress0, OUTPUT);
digitalWrite(pin_adress0, HIGH);
    pinMode(pin_adress1, OUTPUT);
digitalWrite(pin_adress1, HIGH);
    pinMode(pin_adress2, OUTPUT);
digitalWrite(pin_adress2, HIGH);


//define output pin_E1 ( selest 74HC138) select manual
    pinMode( pin_E1_man1, OUTPUT);
digitalWrite( pin_E1_man1, HIGH);
    pinMode( pin_E1_man2, OUTPUT);
digitalWrite( pin_E1_man2, HIGH);
    pinMode( pin_E1_man3, OUTPUT);
digitalWrite( pin_E1_man3, HIGH);
     pinMode( pin_E1_man4, OUTPUT);
digitalWrite( pin_E1_man4, HIGH);
      pinMode( pin_E1_man5, OUTPUT);
digitalWrite( pin_E1_man5, HIGH);
   pinMode( dataPin, OUTPUT);
digitalWrite( dataPin, LOW);
  pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
// define output LED
pinMode(LED_BUILTIN_A4, OUTPUT);


}

void loop()  {
MIDI.read(); // Continuously check if Midi data has been received.
scaner();
  //**************************************

// moduł sygnalizacji działania
//----------------------------------------------------------
unsigned long currentMillis = millis();
// szybkość działania programu
// Serial.println(currentMillis);

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN_A4, ledState);
  }
}

void noteOn(byte cmd, byte data1, byte data2) {
   Serial.write(cmd);
   Serial.write(data1);
   Serial.write(data2);
  
   digitalWrite(LED_BUILTIN_A4, HIGH);
   delay(5);
   digitalWrite(LED_BUILTIN_A4, LOW);
}



void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  
    if (channel == midi_channel) {
      digitalWrite( pin_E1_man1, LOW);
    digitalWrite( pin_E1_man2, LOW);

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
     return;
    }


 
 
   
  


// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
    
    if (channel == midi_channel) {
      digitalWrite( pin_E1_man1, LOW);
    digitalWrite( pin_E1_man2, LOW);

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
     return; 
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



void scaner() {
  //Obsługa man II
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, LOW);
digitalWrite( pin_E1_man3, HIGH);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, HIGH);// właczenie II man do odczytu
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
    }
  }
  }
//*****************************************
//Obsługa man III
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, HIGH);
digitalWrite( pin_E1_man3, LOW);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, HIGH);// właczenie III man do odczytu
channel_on = 0x92; // ustawienie kanałów dla III man - kanal 3
channel_off = 0x82; // kanal 3

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 1-st (first) octet
      for (int i = 0; i <= 7; i++) {
      Key3[i+0*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 2-st (second) octet
      for (int i = 0; i <= 7; i++) {
      Key3[i+1*8] = digitalRead(pin_data[i]);
     }
 
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 3-st (thrid) octet
 
      for (int i = 0; i <= 7; i++) {
      Key3[i+2*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 4-st (quad) octet
 
   for (int i = 0; i <= 7; i++) {
      Key3[i+3*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 5-st (quad) octet
   for (int i = 0; i <= 7; i++) {
      Key3[i+4*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 6-st (qwint) octet
   for (int i = 0; i <= 7; i++) {
      Key3[i+5*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 7-st (sext) octet
   for (int i = 0; i <= 7; i++) {
      Key3[i+6*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 8-st (sept) octet
   for (int i = 0; i <= 7; i++) {
      Key3[i+7*8] = digitalRead(pin_data[i]);
     }
 
 

//****************************************************
// porównywanie odczytów i wysyłanie komunikatów midi dla man III
//
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key3[i] != Key3_last[i] ) {
    if(Key3[i] == 0)  {
      noteOn(channel_on, 36+i, vol);
    }
    else  {
      noteOn(channel_off, 36+i, 0x00);
      noteOn(channel_off, 36+i, 0x00);
    }
  }
  }

  //*****************************************
//Obsługa man IV
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, HIGH);
digitalWrite( pin_E1_man3, HIGH);
digitalWrite( pin_E1_man4, LOW);
digitalWrite( pin_E1_man5, HIGH);// właczenie III man do odczytu
channel_on = 0x93; // ustawienie kanałów dla IV man - kanal 4
channel_off = 0x83; // kanal 4

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 1-st (first) octet
      for (int i = 0; i <= 7; i++) {
      Key4[i+0*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 2-st (second) octet
      for (int i = 0; i <= 7; i++) {
      Key4[i+1*8] = digitalRead(pin_data[i]);
     }
 
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 3-st (thrid) octet
 
      for (int i = 0; i <= 7; i++) {
      Key4[i+2*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 4-st (quad) octet
 
   for (int i = 0; i <= 7; i++) {
      Key4[i+3*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 5-st (quad) octet
   for (int i = 0; i <= 7; i++) {
      Key4[i+4*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 6-st (qwint) octet
   for (int i = 0; i <= 7; i++) {
      Key4[i+5*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 7-st (sext) octet
   for (int i = 0; i <= 7; i++) {
      Key4[i+6*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 8-st (sept) octet
   for (int i = 0; i <= 7; i++) {
      Key4[i+7*8] = digitalRead(pin_data[i]);
     }
 
 

//****************************************************
// porównywanie odczytów i wysyłanie komunikatów midi dla man IV
//
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key4[i] != Key4_last[i] ) {
    if(Key4[i] == 0)  {
      noteOn(channel_on, 36+i, vol);
    }
    else  {
      noteOn(channel_off, 36+i, 0x00);
      noteOn(channel_off, 36+i, 0x00);
    }
  }
  }
    //*****************************************
//Obsługa man V
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, HIGH);
digitalWrite( pin_E1_man3, HIGH);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, LOW);// właczenie III man do odczytu
channel_on = 0x94; // ustawienie kanałów dla IV man - kanal 4
channel_off = 0x84; // kanal 5

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 1-st (first) octet
      for (int i = 0; i <= 7; i++) {
      Key5[i+0*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 2-st (second) octet
      for (int i = 0; i <= 7; i++) {
      Key5[i+1*8] = digitalRead(pin_data[i]);
     }
 
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 3-st (thrid) octet
 
      for (int i = 0; i <= 7; i++) {
      Key5[i+2*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 4-st (quad) octet
 
   for (int i = 0; i <= 7; i++) {
      Key5[i+3*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 5-st (quad) octet
   for (int i = 0; i <= 7; i++) {
      Key5[i+4*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 6-st (qwint) octet
   for (int i = 0; i <= 7; i++) {
      Key5[i+5*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 7-st (sext) octet
   for (int i = 0; i <= 7; i++) {
      Key5[i+6*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 8-st (sept) octet
   for (int i = 0; i <= 7; i++) {
      Key5[i+7*8] = digitalRead(pin_data[i]);
     }
 
 

//****************************************************
// porównywanie odczytów i wysyłanie komunikatów midi dla man V
//
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key5[i] != Key5_last[i] ) {
    if(Key5[i] == 0)  {
      noteOn(channel_on, 36+i, vol);
    }
    else  {
      noteOn(channel_off, 36+i, 0x00);
      noteOn(channel_off, 36+i, 0x00);
    }
  }
  }
//*****************************************************
 
  for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
  Key_last[i] = Key[i];
}
for (int i = 0; i <= LiczbaKlawiszy -1 ; i++) {
  Key2_last[i] = Key2[i];
}
for (int i = 0; i <= LiczbaKlawiszy -1 ; i++) {
  Key3_last[i] = Key3[i];
} 
  for (int i = 0; i <= LiczbaKlawiszy -1 ; i++) {
  Key4_last[i] = Key4[i];
} 
  for (int i = 0; i <= LiczbaKlawiszy -1 ; i++) {
  Key5_last[i] = Key5[i];
} 
//**************************************

// moduł sygnalizacji działania
//----------------------------------------------------------
unsigned long currentMillis = millis();
// szybkość działania programu
// Serial.println(currentMillis);

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN_A4, ledState);
  }
//--------------------------------------------------------------- 
}
