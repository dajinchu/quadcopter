#include <Servo.h>

const int LED = 11; 

boolean count = false;
boolean LEDState = false;

//Servo object
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, HIGH);
  delay(10000);
  digitalWrite(LED, LOW);
  motor1.attach(2);
  motor2.attach(3);
  motor3.attach(4);
  motor4.attach(5);
}

void loop(){
  
  while (Serial.available() == 0);
  int data = Serial.read();
  writeAllMotors(1000 + (data * 3)); 
  analogWrite(LED, data);
  
  Serial.flush();
}

void writeAllMotors(int val) {
  motor1.write(val);
  motor2.write(val);
  motor3.write(val);
  motor4.write(val);
}
