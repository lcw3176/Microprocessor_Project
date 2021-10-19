#include<Stepper.h>

#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28

int steps = 64;

Stepper motor(steps, IN1, IN3, IN2, IN4);


void setup() {
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  motor.setSpeed(100);

}

void loop() {
  for(int i = 0; i < 64; i++){
    motor.step(steps);
  }

  delay(3000);
  
  for(int i = 0; i < 64; i++){
    motor.step(-steps);
  }
  
  delay(3000);
}
