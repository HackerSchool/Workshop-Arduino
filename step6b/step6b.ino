#define BOTAO 2
#define BUZZER 3
#define LDR 0
#define DELAY 500

volatile bool play = false;
volatile long timer = 0; 

void setup() {
  pinMode(BOTAO,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BOTAO), interrupt, FALLING);
}

void loop() {
  int sensor, buzzer, serial_in;
  sensor = analogRead(LDR);
  buzzer = map(sensor,0,1023,500,5000);

  if(!play){
    Serial.println(buzzer);
  }else{
    Serial.println(0);
  }

  if(Serial.available()!=0){
    serial_in = Serial.parseInt();
    if(serial_in==0){
      noTone(BUZZER);
    }else{
      tone(BUZZER,serial_in);
    } 
  }
}

void interrupt(){
  if((millis()-timer > DELAY)){
    play = !play;
    timer = millis();
  } 
}

