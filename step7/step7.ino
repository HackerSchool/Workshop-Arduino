#define BOTAO 2
#define LED 3
#define LDR 0

bool state = false, curr = false, prev = false;

void setup() {
  pinMode(BOTAO,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor, led; 
  sensor = analogRead(LDR);
  led = map(sensor,0,1023,0,255);

  curr = digitalRead(BOTAO);

  if(curr == LOW && prev == HIGH){
    state = !state;
  }
  
  if(!state){
    Serial.println(led);
  }else{
    Serial.println(0);
  }

  if(Serial.available()!=0){
    analogWrite(LED,Serial.parseInt());
  }

  prev = curr;

  delay(100);
}
