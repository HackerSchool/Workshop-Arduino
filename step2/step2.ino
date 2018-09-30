void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor, led;
  sensor = analogRead(0);
  led = map(sensor,0,1023,0,255);
  Serial.println(led);
  
  if(!digitalRead(2)){
    analogWrite(3,led);
  }else{
    analogWrite(3,LOW);
  }

}
