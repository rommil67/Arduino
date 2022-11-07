#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// -----------------------------------------------------------------------------

// This function will be automatically called when a NoteOn is received.
// It must be a void-returning function with the correct parameters,
// see documentation here:
// https://github.com/FortySevenEffects/arduino_midi_library/wiki/Using-Callbacks

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
    // Do whatever you want when a note is pressed.

    // Try to keep your callbacks short (no delays ect)
    // otherwise it would slow down the loop() and have a bad impact
    // on real-time performance.
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
}

// -----------------------------------------------------------------------------
//unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
int ledState = LOW;
// define adress pins for adressed 74HC138
#define pin_adress0 8 //A0
#define pin_adress1 6 //A1
#define pin_adress2 4 //A2
#define pin_E1_man1 10 //A3
#define pin_E1_man2 12 //A4
#define pin_E1_man3 A0 //A5
#define pin_E1_man4 A2 //10
#define pin_E1_man5 A5 //11
#define OE 2 //12
#define LED_BUILTIN_A4 A4

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
int pin_data[] = {A3,A1,13,11,9,7,5,3}; // define data pins
//int pin_data[] = {2,3,4,5,6,7,8,9}; // define data pins

 


int vol = 90; // walue velocity
int channel_on = 1; // kanal 1 - initial variables for midi channel
int channel_off = 1; // kanal 1 - initial variables for midi channel

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




void setup()
{
    
    
    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
    //Serial.begin (31250); //(115200); //(31250); // setup serial for MIDI
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
// define output LED
  pinMode( OE, OUTPUT);
digitalWrite( OE, LOW);
// define output LED
pinMode(LED_BUILTIN_A4, OUTPUT);


}

void loop()
{
    // Call MIDI.read the fastest you can for real-time performance.
    MIDI.read();
//**************************************

 // moduł sygnalizacji działania 
 //----------------------------------------------------------
 unsigned long currentMillis = millis();
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
    digitalWrite(LED_BUILTIN_A4, ledState);
  }
    // There is no need to check if there are messages incoming
    // if they are bound to a Callback function.
    // The attached method will be called automatically
    // when the corresponding message has been received.
    //**************************************
  // vol = analogRead(A5);
  // vol = map(vol, 0, 1023, 0, 127);

   //*****************************************
//Obsługa man I
  digitalWrite( OE, LOW);
  digitalWrite( pin_E1_man1, LOW);
  digitalWrite( pin_E1_man2, HIGH);
  digitalWrite( pin_E1_man3, HIGH);
  digitalWrite( pin_E1_man4, LOW);
  digitalWrite( pin_E1_man5, HIGH);// właczenie I man do odczytu
 
  channel_on = 1; // setup variable chcnell for man. I kanal 1
  channel_off = 1; // ustawienie zmiennych kanału midi dla I man. kanal 1
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 1-st (first) octet
  
      for (int i = 0; i <= 7; i++) {
      Key[i+0*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, LOW); // read 2-st (second) octet
      for (int i = 0; i <= 7; i++) {
      Key[i+1*8] = digitalRead(pin_data[i]);
     }
 
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 3-st (thrid) octet
 
      for (int i = 0; i <= 7; i++) {
      Key[i+2*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, LOW); // read 4-st (quad) octet
 
   for (int i = 0; i <= 7; i++) {
      Key[i+3*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 5-st (quad) octet
   for (int i = 0; i <= 7; i++) {
      Key[i+4*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, LOW);
  digitalWrite(pin_adress2, HIGH); // read 6-st (qwint) octet
   for (int i = 0; i <= 7; i++) {
      Key[i+5*8] = digitalRead(pin_data[i]);
     }

  digitalWrite(pin_adress0, LOW);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 7-st (sext) octet
   for (int i = 0; i <= 7; i++) {
      Key[i+6*8] = digitalRead(pin_data[i]);
     }
  digitalWrite(pin_adress0, HIGH);
  digitalWrite(pin_adress1, HIGH);
  digitalWrite(pin_adress2, HIGH); // read 8-st (sept) octet
   for (int i = 0; i <= 7; i++) {
      Key[i+7*8] = digitalRead(pin_data[i]);
     }
 
 

//****************************************************
// porównywanie odczytów i wysyłanie komunikatów midi

    for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key[i] != Key_last[i] ) {
    if(Key[i] == 0)  {
      MIDI.sendNoteOn(36+i, vol, channel_on);
    }
    else  {
             MIDI.sendNoteOff(36+i, 00, channel_off);
             MIDI.sendNoteOff(36+i, 00, channel_off);
    }
  }
  }
 


//*****************************************
//Obsługa man II
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, LOW);
digitalWrite( pin_E1_man3, HIGH);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, HIGH);// właczenie II man do odczytu
channel_on = 2; // ustawienie kanałów dla II man - kanal 2
channel_off = 2; // kanal 2
   digitalWrite( OE, LOW);
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
      MIDI.sendNoteOn(36+i, vol, channel_on);
    }
    else  {
             MIDI.sendNoteOff(36+i, 00, channel_off);
             MIDI.sendNoteOff(36+i, 00, channel_off);
    }
  }
  }
//*****************************************
//Obsługa man III
  digitalWrite( OE, LOW);
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, HIGH);
digitalWrite( pin_E1_man3, LOW);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, HIGH);// właczenie III man do odczytu
channel_on = 3; // ustawienie kanałów dla III man - kanal 3
channel_off = 3; // kanal 3

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
      MIDI.sendNoteOn(36+i, vol, channel_on);
    }
    else  {
             MIDI.sendNoteOff(36+i, 00, channel_off);
             MIDI.sendNoteOff(36+i, 00, channel_off);
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
channel_on = 4; // ustawienie kanałów dla IV man - kanal 4
channel_off = 4; // kanal 4
digitalWrite( OE, LOW);
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
      MIDI.sendNoteOn(36+i, vol, channel_on);
    }
    else  {
             MIDI.sendNoteOff(36+i, 00, channel_off);
             MIDI.sendNoteOff(36+i, 00, channel_off);
    }
  }
  }
    //*****************************************
//Obsługa man V albo pistony
digitalWrite( OE, HIGH);
digitalWrite( pin_E1_man1, HIGH);
digitalWrite( pin_E1_man2, HIGH); //for pistons
digitalWrite( pin_E1_man3, LOW);
digitalWrite( pin_E1_man4, HIGH);
digitalWrite( pin_E1_man5, LOW);// właczenie III man do odczytu
channel_on = 5; // ustawienie kanałów dla V man - kanal 5
channel_off = 5; // kanal 5

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
// porównywanie odczytów i wysyłanie komunikatów midi dla man V albo pistony
//
   for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
    if(Key5[i] != Key5_last[i] ) {
    if(Key5[i] == 0)  {
      MIDI.sendNoteOn(36+i, vol, channel_on);
    }
    else  {
             MIDI.sendNoteOff(36+i, 00, channel_off);
             MIDI.sendNoteOff(36+i, 00, channel_off);
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
    digitalWrite(LED_BUILTIN_A4, ledState);
}


}
