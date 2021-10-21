#include<Stepper.h>

#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28
#define SWITCH 30

int steps = 64;
bool isRun = false;

Stepper motor(steps, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(9600);
  
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  pinMode(SWITCH, INPUT);
  motor.setSpeed(300);
}
void loop() {
  int input = digitalRead(SWITCH);
  if(input){
    Serial.println("Clockwise");
    motor.step(steps);
  }

  else{
    motor.step(-steps);
  }  
}
