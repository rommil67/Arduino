//Sterowanie zatrzaskiem 74HC595
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

uint32_t p = 0;
uint32_t q = 0;
byte r = 0;

void setup() {
  // put your setup code here, to run once:
// inicjalizacja pinów od zatrzasku
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
/// Zerowanie zatrzasków
}

void loop() {
  // put your main code here, to run repeatedly:
  p = 0b00000000000000000000000000000000;
  p = 0b00000000000000000000000000000000;
  r = 0b00000000;


digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH); 

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH);

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH); 

delay(1000);

  p = 0b11111111111111111111111111111111;
  p = 0b11111111111111111111111111111111;
  r = 0b11111111;

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH); 

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH);

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
shiftOut(dataPin, clockPin, MSBFIRST, r);
digitalWrite(latchPin, HIGH);  

delay(1000);
}
