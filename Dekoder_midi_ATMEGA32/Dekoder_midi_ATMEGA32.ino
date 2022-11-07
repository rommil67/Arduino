//Author Romuald Milewski
#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13
 
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


 

  for (int a=0; a<8; a++)
{
pinMode (a, OUTPUT); // Set Arduino board digital pins to output
digitalWrite (a, LOW); // Set Arduino board digitsl pins to KIGH
    
}
   for (int a=10; a<24; a++)
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
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
 
   for (int a=0; a<8; a=a++){
   if (pitch == 36+a) {
digitalWrite (a, HIGH); // Set Arduino board pin 13 to output
 } 
}


    for (int a=10; a<32; a=a++){
   if (pitch == 44+a) {
digitalWrite (a, HIGH); // Set Arduino board pin 13 to output
 } 
}
  
  
    
   
}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
  
   for (int a=0; a<8; a=a++){
   if (pitch == 36+a) {
digitalWrite (a, LOW); // Set Arduino board pin 13 to output
   } 
 }
   
     for (int a=10; a<32; a=a++){
   if (pitch == 44+a) {
digitalWrite (a, LOW); // Set Arduino board pin 13 to output
 } 
}
  
}  
