/*
Using a 74HC595 Shift Register by swistak / misza
*/
int clockPin = A0;
int latchPin = A1;
int dataPin = 13;
int pin_adress2 = A2;
int pin_E1_man1 = A3;
int pin_E1_man2 = A4;
int pin_E1_man3 = A5;
byte leds = 0;
int currentLED = 0;

void setup()
{
  
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);

 pinMode(pin_adress2, OUTPUT);
 digitalWrite(pin_adress2, HIGH);
pinMode( pin_E1_man1, OUTPUT);
 digitalWrite( pin_E1_man1, LOW);
    pinMode( pin_E1_man2, OUTPUT);
 digitalWrite( pin_E1_man2, LOW);
    pinMode( pin_E1_man3, OUTPUT);
 digitalWrite( pin_E1_man3, LOW);

leds = 0;
}

void loop()
{
leds = 0;

if (currentLED == 7)
{
currentLED = 0;
}
else
{
currentLED++;
}

bitSet(leds, currentLED);

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, LSBFIRST, leds);
digitalWrite(latchPin, HIGH);
/*
TIME LED
*/
delay(250);
}
