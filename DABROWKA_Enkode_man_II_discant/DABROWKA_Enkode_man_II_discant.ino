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
    
    {A0, {note(Gb, 4), CHANNEL_2}},
    {A1, {note(G, 4), CHANNEL_2}},
    {A2, {note(Ab, 4), CHANNEL_2}},
    {A3, {note(A, 4), CHANNEL_2}},
    {A4, {note(Bb, 4), CHANNEL_2}},
    {A5, {note(B, 4), CHANNEL_2}},
    {A6, {note(C, 5), CHANNEL_2}},
    {A7, {note(Db, 5), CHANNEL_2}},
    {0, {note(D, 5), CHANNEL_2}},
    {1, {note(Eb, 5), CHANNEL_2}},
    {2, {note(E, 5), CHANNEL_2}},
    {3, {note(F_, 5), CHANNEL_2}},
    {4, {note(Gb, 5), CHANNEL_2}},
    {5, {note(G, 5), CHANNEL_2}},
    {6, {note(Ab, 5), CHANNEL_2}},
    {7, {note(A, 5), CHANNEL_2}},
    {16, {note(Bb, 5), CHANNEL_2}},
    {17, {note(B, 5), CHANNEL_2}},
    {18, {note(C, 6), CHANNEL_2}},
    {19, {note(Db, 6), CHANNEL_2}},
    {20, {note(D, 6), CHANNEL_2}},
    {21, {note(Eb, 6), CHANNEL_2}},
    {22, {note(E, 6), CHANNEL_2}},
    {23, {note(F_, 6), CHANNEL_2}},
    {10, {note(Gb, 6), CHANNEL_2}},
    {11, {note(G, 6), CHANNEL_2}},
    {15, {note(Ab, 6), CHANNEL_2}},
    {12, {note(A, 6), CHANNEL_2}},
    {13,  {note(Bb, 6), CHANNEL_2}},
    {14,  {note(B, 6), CHANNEL_2}},
  
    
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
