void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);

}

void loop() {
  if(!digitalRead(2)){
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }

}
