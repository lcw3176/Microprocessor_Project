# 중간고사
## 고찰, 개선점
- 처음에는 bool타입 isRun 변수로 스위치 인터럽트를 통해 짜려고 했음
- 그런데 그냥 다 loop문 안에서 처리해도 별 상관 없을 듯 하여 수정함
### 원래 구상한 코드
```c++
#include<Stepper.h>

#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28
#define SWITCH 18

int steps = 64;
volatile bool isRun = false;

Stepper motor(steps, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(9600);
  
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  pinMode(SWITCH, INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH), switch_pressed_event, CHANGE);
  motor.setSpeed(300);
}

void loop() {
  if(isRun){
    Serial.println("Clockwise");
    motor.step(steps);
  }

  else{
    motor.step(-steps);
  }  
}

void switch_pressed_event(){
    isRun != isRun;
}
```