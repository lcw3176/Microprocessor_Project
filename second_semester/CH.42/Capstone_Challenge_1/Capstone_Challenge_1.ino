#include<Stepper.h>

#define IN1 24
#define IN2 26
#define IN3 28
#define IN4 30

int steps = 64;
int cycle = 32;

Stepper motor(steps, IN1, IN3, IN2, IN4);


void setup() {
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  motor.setSpeed(300);
}

void loop() {
  for(int i = 0; i < cycle; i++){
    motor.step(steps);
  }

  delay(3000);
  
  for(int i = 0; i < cycle; i++){
    motor.step(-steps);
  }
  
  delay(3000);
}
