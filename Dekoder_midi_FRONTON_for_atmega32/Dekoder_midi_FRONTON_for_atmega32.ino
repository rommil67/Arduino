//Author Romuald Milewski
#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13

#define decoder_channel 3 // the selected MIDI channel on which the decoder works
#define decoder_pryncypal8_channel 1
#define decoder_copell_ItoP_channel 4


//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {

pinMode (A0, OUTPUT); // Set Arduino board analog pins to output
digitalWrite (A0, LOW);
pinMode (A1, OUTPUT);
digitalWrite (A1, LOW);
pinMode (A2, OUTPUT);
digitalWrite (A2, LOW);
pinMode (A3, OUTPUT);
digitalWrite (A3, LOW);
pinMode (A4, OUTPUT);
digitalWrite (A4, LOW);
pinMode (A5, OUTPUT);
digitalWrite (A5, LOW);
pinMode (A6, OUTPUT);
digitalWrite (A6, LOW);
pinMode (A7, OUTPUT);
digitalWrite (A7, LOW); 
pinMode (A8, OUTPUT);
digitalWrite (A8, LOW);
pinMode (A9, OUTPUT);
digitalWrite (A9, LOW);
pinMode (A10, OUTPUT);
digitalWrite (A10, LOW);
pinMode (A11, OUTPUT);
digitalWrite (A11, LOW);
pinMode (A12, OUTPUT);
digitalWrite (A12, LOW);
pinMode (A13, OUTPUT);
digitalWrite (A13, LOW);
pinMode (A14, OUTPUT);
digitalWrite (A14, LOW);
pinMode (A15, OUTPUT);
digitalWrite (A15, LOW);

 

  for (int a=2; a<54; a++)
{
pinMode (a, OUTPUT); // Set Arduino board digital pins to output
digitalWrite (a, LOW); // Set Arduino board digitsl pins to KIGH
    
}
 

// self-test jesli potrzebny
//  for (int a=16; a<32; a++)
//{
//digitalWrite (a, HIGH); // Set Arduino board digital pins to HIGH
//delay(350); 
//digitalWrite (a, LOW); // Set Arduino board digital pins to LOW
//delay(50);  
//}


 
 





  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
//************************************************************
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
// ******** ON Pedal ********  
  if (channel == decoder_channel) {
   switch (pitch) {
  case 36:
    digitalWrite (A1, HIGH);
    break;
  case 37:
    digitalWrite (A0, HIGH);
    break;
    case 38:
    digitalWrite (A3, HIGH);
    break;
    case 39:
    digitalWrite (A2, HIGH);
    break;
    case 40:
    digitalWrite (A5, HIGH);
    break;
    case 41:
    digitalWrite (A4, HIGH);
    break;
    case 42:
    digitalWrite (A7, HIGH);
    break;
    case 43:
    digitalWrite (A6, HIGH);
    break;
    case 44:
    digitalWrite (A9, HIGH);
    break;
    case 45:
    digitalWrite (A8, HIGH);
    break;
    case 46:
    digitalWrite (A11, HIGH);
    break;
    case 47:
    digitalWrite (A10, HIGH);
    break;
    case 48:
    digitalWrite (A13, HIGH);
    break;
    case 49:
    digitalWrite (A12, HIGH);
    break;
    case 50:
    digitalWrite (A15, HIGH);
    break;
    case 51:
    digitalWrite (A14, HIGH);
    break;
    case 52:
    digitalWrite (33, HIGH);
    break;
    case 53:
    digitalWrite (32, HIGH);
    break;
    case 54:
    digitalWrite (35, HIGH);
    break;
    case 55:
    digitalWrite (34, HIGH);
    break;
    case 56:
    digitalWrite (37, HIGH);
    break;
    case 57:
    digitalWrite (36, HIGH);
    break;
    case 58:
    digitalWrite (39, HIGH);
    break;
    case 59:
    digitalWrite (38, HIGH);
    break;
    case 60:
    digitalWrite (41, HIGH);
    break;
    case 61:
    digitalWrite (40, HIGH);
    break;
    case 62:
    digitalWrite (43, HIGH);
    break;
    case 63:
    digitalWrite (42, HIGH);
    break;
    case 64:
    digitalWrite (45, HIGH);
    break;
    case 65:
    digitalWrite (44, HIGH);
    break;
    case 66:
    digitalWrite (47, HIGH);
    break;
    case 67:
    digitalWrite (46, HIGH);
    break;
    
    
    
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
}
// ******** ON Pryncypał 8 man I ********
if (channel == decoder_pryncypal8_channel) {
   switch (pitch) {
 case 41:
    digitalWrite (3, HIGH);
    break;
    case 42:
    digitalWrite (2, HIGH);
    break;
    case 43:
    digitalWrite (5, HIGH);
    break;
    case 44:
    digitalWrite (4, HIGH);
    break;
    case 45:
    digitalWrite (7, HIGH);
    break;
    case 46:
    digitalWrite (6, HIGH);
    break;
    case 47:
    digitalWrite (9, HIGH);
    break;
    case 48:
    digitalWrite (8, HIGH);
    break;
    case 49:
    digitalWrite (11, HIGH);
    break;
    case 50:
    digitalWrite (10, HIGH);
    break;
    case 51:
    digitalWrite (13, HIGH);
    break;
    case 52:
    digitalWrite (12, HIGH);
    break;
    case 53:
    digitalWrite (15, HIGH);
    break;
    case 54:
    digitalWrite (14, HIGH);
    break;
    case 55:
    digitalWrite (17, HIGH);
    break;
    case 56:
    digitalWrite (16, HIGH);
    break;
    case 57:
    digitalWrite (19, HIGH);
    break;
    case 58:
    digitalWrite (18, HIGH);
    break;
    case 59:
    digitalWrite (21, HIGH);
    break;
    case 60:
    digitalWrite (20, HIGH);
    break;
    case 61:
    digitalWrite (23, HIGH);
    break;
    case 62:
    digitalWrite (22, HIGH);
    break;
    
    case 63:
    digitalWrite (25, HIGH);
    break;
    case 64:
    digitalWrite (24, HIGH);
    break;

    case 65:
    digitalWrite (25, HIGH);
    break;
    case 66:
    digitalWrite (24, HIGH);
    break;

    case 67:
    digitalWrite (27, HIGH);
    break;
    case 68:
    digitalWrite (26, HIGH);
    break;

    case 69:
    digitalWrite (29, HIGH);
    break;
    case 70:
    digitalWrite (28, HIGH);
    break;
     default:
    // if nothing else matches, do the default
    // default is optional
    break;
  
} 
} 
// ******** ON coppell Pedal to Pryncypał 8 man I ********
if (channel == decoder_copell_ItoP_channel) {
   switch (pitch) {
 case 41:
    digitalWrite (3, HIGH);
    break;
    case 42:
    digitalWrite (2, HIGH);
    break;
    case 43:
    digitalWrite (5, HIGH);
    break;
    case 44:
    digitalWrite (4, HIGH);
    break;
    case 45:
    digitalWrite (7, HIGH);
    break;
    case 46:
    digitalWrite (6, HIGH);
    break;
    case 47:
    digitalWrite (9, HIGH);
    break;
    case 48:
    digitalWrite (8, HIGH);
    break;
    case 49:
    digitalWrite (11, HIGH);
    break;
    case 50:
    digitalWrite (10, HIGH);
    break;
    case 51:
    digitalWrite (13, HIGH);
    break;
    case 52:
    digitalWrite (12, HIGH);
    break;
    case 53:
    digitalWrite (15, HIGH);
    break;
    case 54:
    digitalWrite (14, HIGH);
    break;
    case 55:
    digitalWrite (17, HIGH);
    break;
    case 56:
    digitalWrite (16, HIGH);
    break;
    case 57:
    digitalWrite (19, HIGH);
    break;
    case 58:
    digitalWrite (18, HIGH);
    break;
    case 59:
    digitalWrite (21, HIGH);
    break;
    case 60:
    digitalWrite (20, HIGH);
    break;
    case 61:
    digitalWrite (23, HIGH);
    break;
    case 62:
    digitalWrite (22, HIGH);
    break;
    
    case 63:
    digitalWrite (25, HIGH);
    break;
    case 64:
    digitalWrite (24, HIGH);
    break;

    case 65:
    digitalWrite (25, HIGH);
    break;
    case 66:
    digitalWrite (24, HIGH);
    break;

    case 67:
    digitalWrite (27, HIGH);
    break;
    case 68:
    digitalWrite (26, HIGH);
    break;

    case 69:
    digitalWrite (29, HIGH);
    break;
    case 70:
    digitalWrite (28, HIGH);
    break;
     default:
    // if nothing else matches, do the default
    // default is optional
    break;
  
} 
}     
   
}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
//******************************************************************
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
 // ******** OFF Pedal ********  
  if (channel == decoder_channel) {
   switch (pitch) {
  case 36:
    digitalWrite (A1, LOW);
    break;
  case 37:
    digitalWrite (A0, LOW);
    break;
    case 38:
    digitalWrite (A3, LOW);
    break;
    case 39:
    digitalWrite (A2, LOW);
    break;
    case 40:
    digitalWrite (A5, LOW);
    break;
    case 41:
    digitalWrite (A4, LOW);
    break;
    case 42:
    digitalWrite (A7, LOW);
    break;
    case 43:
    digitalWrite (A6, LOW);
    break;
    case 44:
    digitalWrite (A9, LOW);
    break;
    case 45:
    digitalWrite (A8, LOW);
    break;
    case 46:
    digitalWrite (A11, LOW);
    break;
    case 47:
    digitalWrite (A10, LOW);
    break;
    case 48:
    digitalWrite (A13, LOW);
    break;
    case 49:
    digitalWrite (A12, LOW);
    break;
    case 50:
    digitalWrite (A15, LOW);
    break;
    case 51:
    digitalWrite (A14, LOW);
    break;
    case 52:
    digitalWrite (33, LOW);
    break;
    case 53:
    digitalWrite (32, LOW);
    break;
    case 54:
    digitalWrite (35, LOW);
    break;
    case 55:
    digitalWrite (34, LOW);
    break;
    case 56:
    digitalWrite (37, LOW);
    break;
    case 57:
    digitalWrite (36, LOW);
    break;
    case 58:
    digitalWrite (39, LOW);
    break;
    case 59:
    digitalWrite (38, LOW);
    break;
    case 60:
    digitalWrite (41, LOW);
    break;
    case 61:
    digitalWrite (40, LOW);
    break;
    case 62:
    digitalWrite (43, LOW);
    break;
    case 63:
    digitalWrite (42, LOW);
    break;
    case 64:
    digitalWrite (45, LOW);
    break;
    case 65:
    digitalWrite (44, LOW);
    break;
    case 66:
    digitalWrite (47, LOW);
    break;
    case 67:
    digitalWrite (46, LOW);
    break;
    
    
    
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
}
// ******** OFF Pryncypał 8 man I ********
if (channel == decoder_pryncypal8_channel) {
   switch (pitch) {
 case 41:
    digitalWrite (3, LOW);
    break;
    case 42:
    digitalWrite (2, LOW);
    break;
    case 43:
    digitalWrite (5, LOW);
    break;
    case 44:
    digitalWrite (4, LOW);
    break;
    case 45:
    digitalWrite (7, LOW);
    break;
    case 46:
    digitalWrite (6, LOW);
    break;
    case 47:
    digitalWrite (9, LOW);
    break;
    case 48:
    digitalWrite (8, LOW);
    break;
    case 49:
    digitalWrite (11, LOW);
    break;
    case 50:
    digitalWrite (10, LOW);
    break;
    case 51:
    digitalWrite (13, LOW);
    break;
    case 52:
    digitalWrite (12, LOW);
    break;
    case 53:
    digitalWrite (15, LOW);
    break;
    case 54:
    digitalWrite (14, LOW);
    break;
    case 55:
    digitalWrite (17, LOW);
    break;
    case 56:
    digitalWrite (16, LOW);
    break;
    case 57:
    digitalWrite (19, LOW);
    break;
    case 58:
    digitalWrite (18, LOW);
    break;
    case 59:
    digitalWrite (21, LOW);
    break;
    case 60:
    digitalWrite (20, LOW);
    break;
    case 61:
    digitalWrite (23, LOW);
    break;
    case 62:
    digitalWrite (22, LOW);
    break;
    
    case 63:
    digitalWrite (25, LOW);
    break;
    case 64:
    digitalWrite (24, LOW);
    break;

    case 65:
    digitalWrite (25, LOW);
    break;
    case 66:
    digitalWrite (24, LOW);
    break;

    case 67:
    digitalWrite (27, LOW);
    break;
    case 68:
    digitalWrite (26, LOW);
    break;

    case 69:
    digitalWrite (29, LOW);
    break;
    case 70:
    digitalWrite (28, LOW);
    break;
     default:
    // if nothing else matches, do the default
    // default is optional
    break;
  
} 
} 
// ******** OFF coppell Pedal to Pryncypał 8 man I ********
if (channel == decoder_copell_ItoP_channel) {
   switch (pitch) {
 case 41:
    digitalWrite (3, LOW);
    break;
    case 42:
    digitalWrite (2, LOW);
    break;
    case 43:
    digitalWrite (5, LOW);
    break;
    case 44:
    digitalWrite (4, LOW);
    break;
    case 45:
    digitalWrite (7, LOW);
    break;
    case 46:
    digitalWrite (6, LOW);
    break;
    case 47:
    digitalWrite (9, LOW);
    break;
    case 48:
    digitalWrite (8, LOW);
    break;
    case 49:
    digitalWrite (11, LOW);
    break;
    case 50:
    digitalWrite (10, LOW);
    break;
    case 51:
    digitalWrite (13, LOW);
    break;
    case 52:
    digitalWrite (12, LOW);
    break;
    case 53:
    digitalWrite (15, LOW);
    break;
    case 54:
    digitalWrite (14, LOW);
    break;
    case 55:
    digitalWrite (17, LOW);
    break;
    case 56:
    digitalWrite (16, LOW);
    break;
    case 57:
    digitalWrite (19, LOW);
    break;
    case 58:
    digitalWrite (18, LOW);
    break;
    case 59:
    digitalWrite (21, LOW);
    break;
    case 60:
    digitalWrite (20, LOW);
    break;
    case 61:
    digitalWrite (23, LOW);
    break;
    case 62:
    digitalWrite (22, LOW);
    break;
    
    case 63:
    digitalWrite (25, LOW);
    break;
    case 64:
    digitalWrite (24, LOW);
    break;

    case 65:
    digitalWrite (25, LOW);
    break;
    case 66:
    digitalWrite (24, LOW);
    break;

    case 67:
    digitalWrite (27, LOW);
    break;
    case 68:
    digitalWrite (26, LOW);
    break;

    case 69:
    digitalWrite (29, LOW);
    break;
    case 70:
    digitalWrite (28, LOW);
    break;
     default:
    // if nothing else matches, do the default
    // default is optional
    break;
  
} 
}     
   
}
  
