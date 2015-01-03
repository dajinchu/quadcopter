const int LED = 11; 
const int BUTTON = 7;

boolean on = false;
int prevButtonState;
int in = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop()
{
  in = digitalRead(BUTTON);
  if(in == HIGH){
    Serial.write(128);
    delay(50);
    digitalWrite(LED,HIGH);
  }else{
    Serial.write(0);
    delay(50);
    digitalWrite(LED,LOW);
  }
}
