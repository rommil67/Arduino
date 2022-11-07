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

//Potenciometrs
CCPotentiometer potentiometer1(A4, {MIDI_CC::Channel_Volume, CHANNEL_9});
//CCPotentiometer potentiometer2(A7, {MIDI_CC::Channel_Volume, CHANNEL_4});
//CCPotentiometer potentiometer3(A3, {MIDI_CC::Channel_Volume, CHANNEL_13});
//CCPotentiometer potentiometer4(A4, {MIDI_CC::Channel_Volume, CHANNEL_14});
//CCPotentiometer potentiometer5(A5, {MIDI_CC::Channel_Volume, CHANNEL_15});
// The note numbers corresponding to the buttons in the matrix

// The note numbers corresponding to the buttons in the matrix
// inny kirunek diód
const AddressMatrix<8, 4> addresses = {{
  { 36, 44, 52, 60 }, //, 68, 76, 84, 92 },
  { 37, 45, 53, 61 },  //, 69, 77, 84, 93 },
  { 38, 46, 54, 62 },//, 70, 78, 86, 94 },
  { 39, 47, 55, 63 },//, 71, 79, 87, 95 },
  { 40, 48, 56, 64 },//, 72, 80, 88, 96 },
  { 41, 49, 57, 65 },//, 73, 81, 89, 97 },
  { 42, 50, 58, 66 },//, 74, 82, 90, 98 },
  { 43, 51, 59, 67 },//, 75, 83, 91, 99 },
  
}};

NoteButtonMatrix<8, 4> buttonmatrix = {
  
 {2, 3, 4, 5, 6, 7, 8, 9}, // row pins
 {A0, A1, A2, A3},// column pins
  addresses, // address matrix
  CHANNEL_3, // channel and cable number
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
