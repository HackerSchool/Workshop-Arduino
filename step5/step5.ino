#define BOTAO 2
#define LED 3
#define LDR 0

void setup() {
  pinMode(BOTAO,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor, led;
  sensor = analogRead(LDR);
  led = map(sensor,0,1023,0,255);
  
  if(!digitalRead(BOTAO)){
    Serial.println(led);
  }else{
    Serial.println(0);
  }

  if(Serial.available()!=0){
    analogWrite(LED,Serial.parseInt());
  }

}
