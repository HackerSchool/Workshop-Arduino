#define BOTAO 2
#define BUZZER 3
#define LDR 0

bool state = false, curr = false, prev = false;

void setup() {
  pinMode(BOTAO,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sensor, buzzer, serial_in;
  sensor = analogRead(LDR);
  buzzer = map(sensor,0,1023,500,5000);

  curr = digitalRead(BOTAO);
  
  if(curr == LOW && prev == HIGH){
    state = !state;
  }

  if(!state){
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

  prev = curr;
}

