const int LED = 11; 
const int POTENTIOMETER = 2;

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
  if(prevButtonState != in){
    //If pot got turned
    Serial.write(in / 4);
    delay(50);
    analogWrite(LED, in/4);
    prevButtonState = in;
  }
}
