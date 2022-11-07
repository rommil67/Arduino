/**
 * Pipe organ kemper PEDAL Key - first 14 key
 * for ATmega328p or Arduino uno, nano, pro mini
 * or MIDIuino :), superOCTAVcoppel 
 * Autor: Romuald Milewski
 *
 * 
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
HardwareSerialMIDI_Interface midiser = Serial; //Interface serial
//HairlessMIDI_Interface midiser;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;

// Instantiate the momentary push buttons that send out MIDI Note events.
NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano
    {7, {note(C, 2), CHANNEL_3}},
    {2, {note(Db, 2), CHANNEL_3}},
    {6, {note(D, 2), CHANNEL_3}},
    {3, {note(Eb, 2), CHANNEL_3}},
    {5, {note(E, 2), CHANNEL_3}},
    {4, {note(F_, 2), CHANNEL_3}},
    {A2, {note(Gb, 2), CHANNEL_3}},
    {A3, {note(G, 2), CHANNEL_3}},
    {A1, {note(Ab, 2), CHANNEL_3}},
    {A4, {note(A, 2), CHANNEL_3}},
    {A0, {note(Bb, 2), CHANNEL_3}},
    {A5, {note(B, 2), CHANNEL_3}},
    {13, {note(C, 3), CHANNEL_3}}, // remove led in nano
    {8, {note(Db, 3), CHANNEL_3}},
  //{12, {note(D, 3), CHANNEL_3}},
  //{9, {note(Eb, 3), CHANNEL_3}},
  //{11, {note(E, 3), CHANNEL_3}},
  //{10, {note(F, 3), CHANNEL_3}},
    
    
    
  
    
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
