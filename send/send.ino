#include <math.h>

const int LED = 11; 
const int POTENTIOMETER = 2;

boolean on = false;
int prevButtonState;
int in = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  prevButtonState = analogRead(POTENTIOMETER);
}

void loop()
{
  in = analogRead(POTENTIOMETER);
  Serial.write(128);
  analogWrite(LED, in/4);
}
