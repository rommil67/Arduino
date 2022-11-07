/*
 * I_man_ZAMBROW_NEW-ver_Midi_matrix_for_micro__7x8_keyboard_in_surfacecontroll
 * Author: R. Milewski
 * for nano and uno
 *
 * 
 *  Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */
#include <Control_Surface.h>
//Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midiser;

MIDI_PipeFactory<1> pipes;

// The note numbers corresponding to the buttons in the matrix
// inny kirunek diód
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

NoteButtonMatrix<8, 8> buttonmatrix = {

  {A14, A12, A10, A8, A6, A4, A2, A0}, // row pins
  {A15, A11, A7, A3, A13, A9, A5, A1}, // column pins
  
  addresses, // address matrix
  CHANNEL_1, // channel and cable number
};
void setup() {
  // Initialize everything
Control_Surface.begin();
 midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();
}

void loop() {
  // Update the control surface
Control_Surface.loop();
 midiser.update();
}
