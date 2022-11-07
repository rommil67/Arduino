/**
 * pedal
 * for  Arduino nano or mega
 * @brief   This example demonstrates the use of push buttons that send note 
 *          events.
 * 
 * ### Connections
 * 
 *  - 2:  momentary push button (to ground)
 *  - 3:  momentary push button (to ground)
 * 
 * The internal pull-up resistors for the buttons will be enabled automatically.
 * 
 * ### Behavior
 * 
 * Pressing the first button will send note on/off events on middle C.
 * Pressing the second button will send note on/off events for middle C sharp.
 * 
 * Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */

// Include the Control Surface library
#include <Control_Surface.h>

// Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midi;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;
/* Instantiate the momentary push buttons that send out MIDI Note events.
//NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano
    {12, {note(C, 7), CHANNEL_9}},
 //   {13, {note(Db, 7), CHANNEL_5}},
//    {A0, {note(D, 7), CHANNEL_9}},
  //  {A1, {note(Eb, 7), CHANNEL_5}},
  //  {A2, {note(E, 7), CHANNEL_5}},
 //   {A3, {note(F, 7), CHANNEL_5}},
  //  {A4, {note(Gb, 7), CHANNEL_5}},
  //  {A5, {note(G, 7), CHANNEL_5}},
  
//};
*/

//Potenciometrs
CCPotentiometer potentiometer1(A4, {MIDI_CC::Channel_Volume, CHANNEL_11});
CCPotentiometer potentiometer2(A5, {MIDI_CC::Channel_Volume, CHANNEL_12});
CCPotentiometer potentiometer3(A6, {MIDI_CC::Channel_Volume, CHANNEL_13});
//CCPotentiometer potentiometer4(A4, {MIDI_CC::Channel_Volume, CHANNEL_14});
//CCPotentiometer potentiometer5(A5, {MIDI_CC::Channel_Volume, CHANNEL_15});
// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<4, 8> addresses = {{
   {36, 37, 38, 39, 40, 41, 42, 43},
  {44, 45, 46, 47, 48,  49, 50, 51},
  {52, 53, 54, 55, 56, 57, 58, 59},
  {60, 61, 62, 63, 64, 65, 66, 67},
   
}};

NoteButtonMatrix<4, 8> buttonmatrix = {
   {A0, A1, A2, A3}, // row pins 
   {9, 8, 7, 6, 5, 4, 3, 2}, // column pins
 
  
  addresses,    // address matrix
  CHANNEL_6,    // channel and cable number
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
