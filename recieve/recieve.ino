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
  int data = Serial.read() - '0'; 
  if (data == HIGH){
    digitalWrite(LED, HIGH);
  }
  else if(data == LOW) {
    digitalWrite(LED, LOW);
  }
  
  Serial.flush();
  
}

