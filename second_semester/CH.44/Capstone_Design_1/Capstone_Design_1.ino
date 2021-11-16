#define sensor 18
#define ledOne 24
#define ledTwo 26
#define buzzer 28

int samplingTime = 1500;
volatile unsigned long mill = 0;
volatile int count = 0;

bool ledOneState = false;
bool ledTwoState = false;
bool buzzerState = false;

void setup() {
  pinMode(sensor, INPUT);
  
  for(int i = ledOne; i <= buzzer; i++){
    pinMode(i, OUTPUT);  
  }

  attachInterrupt(digitalPinToInterrupt(sensor), clapEvent, FALLING);
}

void loop() {
  if(count){
    while(millis() - mill < samplingTime){

    }

    switch(count){
      case 1:
        ledOneState = !ledOneState;
        digitalWrite(ledOne, ledOneState);
        break;
      case 2:
        ledTwoState = !ledTwoState;
        digitalWrite(ledTwo, ledTwoState);
        break;
      case 3:
        buzzerState = !buzzerState;
        digitalWrite(buzzer, buzzerState);
        break;
      default:
        break;
      }

    count = 0;
  }
}

void clapEvent(){
  
  // 중복 실행 방지
  if(millis() - mill < 300){
    return;
  }
  
  mill = millis();
  count++;
}
