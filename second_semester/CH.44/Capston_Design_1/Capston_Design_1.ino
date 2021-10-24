#define sensor 18
#define ledOne 24
#define ledTwo 26
#define buzzer 28

const int clapInterval = 500;
volatile unsigned long millsArr[2] = {0, 0};

volatile bool singleClap = false;
volatile bool doubleClap = false;
volatile bool tripleClap = false;

void setup() {
  pinMode(sensor, INPUT);
  
  for(int i = ledOne; i <= buzzer; i++){
    pinMode(i, OUTPUT);  
  }

  attachInterrupt(digitalPinToInterrupt(sensor), clapEvent, FALLING);
}

void loop() {
  digitalWrite(ledOne, singleClap);
  digitalWrite(ledTwo, doubleClap);
  digitalWrite(buzzer, tripleClap);
}

void clapEvent(){
  
  // 한번 박수
  if(millis() - millsArr[0] > clapInterval){
    singleClap = !singleClap;
  }
  
  // 두번 박수
  if(millis() - millsArr[0] <= clapInterval){
    millsArr[1] = millis();
    doubleClap = !doubleClap;
  } 

  // 세번 박수
  if(millis() - millsArr[1] <= clapInterval){
    tripleClap = !tripleClap;
  }
  
  millsArr[0] = millis();
}
