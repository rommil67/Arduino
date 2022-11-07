#include <Control_Surface.h>
 
//USBMIDI_Interface midi;
//HardwareSerialMIDI_Interface serialmidi = {Serial, MIDI_BAUD};
HairlessMIDI_Interface midi;

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

NoteButtonMatrix<8, 8> buttonmatrix = {

  {2, 3, 4, 5, 6, 7, 8, 9}, // row pins
  {A5, A3, A1, 10, A4, A2, A0, 11}, // column pins
  
  addresses, // address matrix
  CHANNEL_1, // channel and cable number
};

NoteButtonMatrix<8, 8> buttonmatrix1 = {
  {31, 32, 33, 34, 35, 36, 37, 38}, // row pins
  {41, 42, 43, 44, 45, 46, 47, 48},    // column pins
  addresses1,    // address matrix
  CHANNEL_2,    // channel and cable number
}; 
void setup() {
  Control_Surface.begin();
}
 
void loop() {
  Control_Surface.loop();
}
