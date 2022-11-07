#include <Control_Surface.h>
 
//USBMIDI_Interface midi;
//Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midiser;

MIDI_PipeFactory<1> pipes;

// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<8, 8> addresses = {{
  { 36, 44, 52, 60, 68, 76, 84, 92 },
  { 37, 45, 53, 61, 69, 77, 84, 93 },
  { 38, 46, 54, 62, 70, 78, 86, 94 },
  { 39, 47, 55, 63, 71, 79, 87, 95 },
  { 40, 48, 56, 64, 72, 80, 88, 96 },
  { 41, 49, 57, 65, 73, 81, 89, 97 },
  { 42, 50, 58, 66, 74, 82, 90, 98 },
  { 43, 51, 59, 67, 75, 83, 91, 99 },
  
}};

 const AddressMatrix<8, 8> addresses1 = {{
  { 36, 44, 52, 60, 68, 76, 84, 92 },
  { 37, 45, 53, 61, 69, 77, 84, 93 },
  { 38, 46, 54, 62, 70, 78, 86, 94 },
  { 39, 47, 55, 63, 71, 79, 87, 95 },
  { 40, 48, 56, 64, 72, 80, 88, 96 },
  { 41, 49, 57, 65, 73, 81, 89, 97 },
  { 42, 50, 58, 66, 74, 82, 90, 98 },
  { 43, 51, 59, 67, 75, 83, 91, 99 },
  
}};

 const AddressMatrix<8, 8> addresses2 = {{
  { 36, 44, 52, 60, 68, 76, 84, 92 },
  { 37, 45, 53, 61, 69, 77, 84, 93 },
  { 38, 46, 54, 62, 70, 78, 86, 94 },
  { 39, 47, 55, 63, 71, 79, 87, 95 },
  { 40, 48, 56, 64, 72, 80, 88, 96 },
  { 41, 49, 57, 65, 73, 81, 89, 97 },
  { 42, 50, 58, 66, 74, 82, 90, 98 },
  { 43, 51, 59, 67, 75, 83, 91, 99 },
  
}};

NoteButtonMatrix<8, 8> buttonmatrix = {

//  {2, 3, 4, 5, 6, 7, 8, 9}, // row pins
//  {A5, A3, A1, 10, A4, A2, A0, 11}, // column pins
  {A14, A12, A10, A8, A6, A4, A2, A0}, // row pins
  {A15, A11, A7, A3, A13, A9, A5, A1}, // column pins
  addresses, // address matrix
  CHANNEL_1, // channel and cable number
};

NoteButtonMatrix<8, 8> buttonmatrix1 = {
  {32, 34, 36, 38, 40, 42, 44, 46}, // row pins
  {33, 37, 41, 45, 35, 39, 43, 47},    // column pins
  addresses1,    // address matrix
  CHANNEL_2,    // channel and cable number
}; 

NoteButtonMatrix<8, 8> buttonmatrix2 = {
  {16, 18, 20, 22, 24, 26, 28, 30}, // row pins
  {17, 21, 25, 29, 19, 23, 27, 31},    // column pins
  addresses2,    // address matrix
  CHANNEL_3,    // channel and cable number
}; 
void setup() {
  Control_Surface.begin();
   midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();
}
 
void loop() {
  Control_Surface.loop();
    midiser.update();
}
