#include <Servo.h>

const int LED = 13; 

boolean count = false;
boolean LEDState = false;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, HIGH);
  delay(10000);
  digitalWrite(LED, LOW);
}

void loop(){
  
  while (Serial.available() == 0);
  int data = Serial.read(); 
  if (data == 255){
    digitalWrite(LED, HIGH);
  }
  else if(data == 0) {
    digitalWrite(LED, LOW);
  }
  
  Serial.flush();
  
}

