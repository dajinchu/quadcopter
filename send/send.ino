#include <math.h>

const int LED = 11; 
const int POTENTIOMETER = 2;

boolean on = false;
int prevButtonState;
int val = 0;
int in = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  prevButtonState = analogRead(POTENTIOMETER);
}

void loop()
{
  while((in=analogRead(POTENTIOMETER))==prevButtonState);
  //If pot got turned
  Serial.write(in / 4);
  analogWrite(LED, in/4);
  prevButtonState = in;
}
