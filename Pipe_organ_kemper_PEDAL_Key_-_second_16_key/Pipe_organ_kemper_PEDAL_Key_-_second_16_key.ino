/**
 * Pipe organ kemper PEDAL Key - first 14 key
 * for ATmega328p or Arduino uno, nano, pro mini
 * Autor: Romuald Milewski
 *
 * The third processor for registers converted Yamaha E-10AR to a MIDI console
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
    {2, {note(D, 3), CHANNEL_3}},
    {3, {note(Eb, 3), CHANNEL_3}},
    {4, {note(E, 3), CHANNEL_3}},
    {5, {note(F_, 3), CHANNEL_3}},
    {6, {note(Gb, 3), CHANNEL_3}},
    {7, {note(G, 3), CHANNEL_3}},
    {8, {note(Ab, 3), CHANNEL_3}},
    {9, {note(A, 3), CHANNEL_3}},
    {10, {note(Bb, 3), CHANNEL_3}},
    {11, {note(B, 3), CHANNEL_3}},
    {12, {note(C, 4), CHANNEL_3}},
    {13, {note(Db, 4), CHANNEL_3}}, // remove led in nano
    {A0, {note(D, 4), CHANNEL_3}},
    {A1, {note(Eb, 4), CHANNEL_3}}, 
    {A2, {note(E, 4), CHANNEL_3}},
    {A3, {note(F_, 4), CHANNEL_3}},
  //{A4, {note(Gb, 4), CHANNEL_3}},
  //{A5, {note(G, 4), CHANNEL_3}},
  //{A4, {note(E, 3), CHANNEL_3}},
  //{A5, {note(F, 3), CHANNEL_3}},
    
    
    
  
    
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
