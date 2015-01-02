#include <Servo.h>

//Input pins
const int lowestPin = 8;
const int halfPin = 9;
const int fullPin = 10;

//LED output pins
const int LED1 =  13;
const int LED2 =  12;
const int LED3 =  11;

//Servo object
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

//Stored state(HIGH/LOW)
int lowestState = 0;
int halfState = 0;
int fullState = 0;

void setup(){
  pinMode(lowestPin, INPUT_PULLUP);
  pinMode(halfPin, INPUT_PULLUP);
  pinMode(fullPin, INPUT_PULLUP);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT);
  motor1.attach(2);
  motor2.attach(3);
  motor3.attach(4);
  motor4.attach(5);
}
void loop(){
  lowestState = digitalRead(lowestPin);
  halfState = digitalRead(halfPin);
  fullState = digitalRead(fullPin);

  
  if(fullState == LOW){//using pullup, so this is off
    full();//fullState first, so basically the highest power wins
  }else if(halfState == LOW){
    half();
  }else if(lowestState == LOW){
    lowest();
  }else{
    off();//Turn it OFF
  }
}

void off(){
  servoWriteAll(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void full(){
  servoWriteAll(2000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void half(){
  servoWriteAll(1500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
}

void lowest(){
  servoWriteAll(1200);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
}

void servoWriteAll(int val){
  motor1.write(val);
  motor2.write(val);
  motor3.write(val);
  motor4.write(val);
}



  
