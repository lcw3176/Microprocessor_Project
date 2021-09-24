#include<Stepper.h>

#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28

Stepper motor(64, IN1, IN2, IN3, IN4);
int steps = 4096;

void setup() {
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  motor.setSpeed(100);

}

void loop() {
  motor.step(steps);
  delay(3000);
  motor.step(-steps);
  delay(3000);
}
