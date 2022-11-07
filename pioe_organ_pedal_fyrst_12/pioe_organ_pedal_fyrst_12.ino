/**
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
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midi;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;

// Instantiate the momentary push buttons that send out MIDI Note events.
NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano
    {12, {note(C, 2), CHANNEL_5}},
    {11, {note(Db, 2), CHANNEL_5}},
    {10, {note(D, 2), CHANNEL_5}},
    {9, {note(Eb, 2), CHANNEL_5}},
    {8, {note(E, 2), CHANNEL_5}},
    {7, {note(F, 2), CHANNEL_5}},
    {6, {note(Gb, 2), CHANNEL_5}},
    {5, {note(G, 2), CHANNEL_5}},
    {4, {note(Ab, 2), CHANNEL_5}},
    {3, {note(A, 2), CHANNEL_5}},
    {2, {note(Bb, 2), CHANNEL_5}},
    {A5, {note(B, 2), CHANNEL_5}},
    {A4, {note(C, 3), CHANNEL_5}},
    {A3, {note(Db, 3), CHANNEL_5}},
    {A2, {note(D, 3), CHANNEL_5}},
    {A1, {note(Eb, 3), CHANNEL_5}},
    {A0, {note(E, 3), CHANNEL_5}},
    {13, {note(F, 3), CHANNEL_5}},
    
    
    
  
    
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
