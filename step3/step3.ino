void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor, led;
  sensor = analogRead(0);
  led = map(sensor,0,1023,0,255);
  
  if(!digitalRead(2)){
    Serial.println(led);
  }else{
    Serial.println(0);
  }

  if(Serial.available()!=0){
    analogWrite(3,Serial.parseInt());
  }

}
