unsigned long lastCall = 0;

int timeSinceLastCall(){
  long ret = millis()-lastCall;
  lastCall = millis();
  return ret;
}
  
