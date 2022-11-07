#include <Control_Surface.h>
 
// Create two MIDI interfaces
USBMIDI_Interface usbmidi;
HardwareSerialMIDI_Interface serialmidi {Serial1, MIDI_BAUD};
 
// Create a MIDI pipe factory to connect the MIDI interfaces to Control Surface
BidirectionalMIDI_PipeFactory<2> pipes;
 
// Add some MIDI elements to show that the MIDI interfaces actually work
CCPotentiometer pot {A0, MIDI_CC::General_Purpose_Controller_1};
NoteLED led {9, 0x3C};
 
void setup() {
  // Manually connect the MIDI interfaces to Control Surface
  Control_Surface | pipes | usbmidi;
  Control_Surface | pipes | serialmidi;
  // Initialize Control Surface _after_ connecting the interfaces
  Control_Surface.begin();
}
 
void loop() {
  Control_Surface.loop();
}
 
/*
 * The vertical pipe operator (|) is used to make a bidirectional connection 
 * between a MIDI sink or source and a MIDI pipe.
 * You can also use unidirectional pipes. These can be connected using the 
 * stream operators (<< and >>).
 * 
 * For example:
 * 
 *     MIDI_PipeFactory<2> pipes;
 *     ...
 *       Control_Surface >> pipes >> usbmidi;    // Output to usbmidi
 *       Control_Surface << pipes << serialmidi; // Input from serialmidi
 */
