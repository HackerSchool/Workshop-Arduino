void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor, led, serial_in;
  sensor = analogRead(0);
  led = map(sensor,0,1023,500,5000);
  
  if(!digitalRead(2)){
    Serial.println(led);
  }else{
    Serial.println(0);
  }

  if(Serial.available()!=0){
    serial_in = Serial.parseInt();
    if(serial_in==0){
      noTone(3);
    }else{
      tone(3,serial_in);
    }
    
  }

}
