/**
 * This example demonstrates the use of LEDs that respond to incoming  MIDI
 * note events.
 * 
 * @boards  AVR, AVR USB, Nano Every, Due, Nano 33 IoT, Nano 33 BLE, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 * None.
 * 
 * Behavior
 * --------
 * 
 * If a MIDI Note On event for note 0x3C (C4 or middle C) is sent, the built-in 
 * LED will light up, if a Note Off event for that note is sent, the LED will 
 * turn off.  
 * (A Note On event with a velocity of zero also counts as a Note Off event.)
 * 
 * Mapping
 * -------
 * 
 * Route the MIDI output of a MIDI keyboard to the Arduino's MIDI input. Then
 * play a middle C on the keyboard.
 * 
 * Written by PieterP, 2019-02-07  
 * https://github.com/tttapa/Control-Surface
 */

#include <Control_Surface.h> // Include the Control Surface library

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;

// Instantiate the LED that will light up when middle C is playing
NoteLED ledC {
  2, 
  {MIDI_Notes::C(4), CHANNEL_1},
};
NoteLED ledDb {
  3, 
  {MIDI_Notes::Db(4), CHANNEL_1},
};
NoteLED ledD {
  4, 
  {MIDI_Notes::D(4), CHANNEL_1},
};
NoteLED ledEb {
  5, 
  {MIDI_Notes::Eb(4), CHANNEL_1},
};
NoteLED ledE {
  6, 
  {MIDI_Notes::E(4), CHANNEL_1},
};
NoteLED ledF {
  7, 
  {MIDI_Notes::F_(4), CHANNEL_1},
};
NoteLED ledGb {
  8, 
  {MIDI_Notes::Gb(4), CHANNEL_1},
};
NoteLED ledG {
  9, 
  {MIDI_Notes::Gb(4), CHANNEL_1},
};

void setup() {
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
}
