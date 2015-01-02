const int LED = 13; 
const int BUTTON = 7;
const int FALSE= -1;
const int TRUE = 1;

boolean on = false;
boolean prevButtonState = false;
int val = 0;
int in = LOW;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); 
  Serial.begin(9600); 
}

void loop()
{
  in = digitalRead(BUTTON);
  if(in == HIGH) {
    if(!prevButtonState) {
      if(!on) {
        Serial.println(HIGH);
        delay(50);
      }
      if(on){
        Serial.println(LOW);
        delay(50);    
      }
      on = !on;
    }
    prevButtonState = true;
  }
  else if(in == LOW) {
    prevButtonState = false;  
  }
  
  if(!on) {
    digitalWrite(LED, LOW);
  }
  if(on) {
    digitalWrite(LED, HIGH);
  }
}
