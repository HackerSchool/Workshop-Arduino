#define BOTAO 2
#define LED 3

void setup() {
  pinMode(BOTAO,INPUT_PULLUP);
  pinMode(LED,OUTPUT);

}

void loop() {
  if(!digitalRead(BOTAO)){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }

}
