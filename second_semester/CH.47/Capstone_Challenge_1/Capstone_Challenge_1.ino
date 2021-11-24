#define sensor 22
#define buzzer 23
int value;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  value = digitalRead(sensor);

  if(!value){
    digitalWrite(buzzer, HIGH);
    delay(200);
  } else{
    digitalWrite(buzzer, LOW);
    delay(200);
  }
}
