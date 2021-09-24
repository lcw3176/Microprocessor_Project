#include<Stepper.h>
#include <MsTimer2.h>

#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28

#define echo 9
#define trigger 10

Stepper motor(64, IN1, IN2, IN3, IN4);
int step_half = 32;
int step_count = 0;
int step_level = 64;

bool isReverse = false;
bool isRepeat = false;

void setup() {
  for(int i = IN1; i <= IN4; i+=2){
    pinMode(i, OUTPUT);
  }

  motor.setSpeed(100);
}

void loop() {
  long distance = getDistanceFromSensor();
  if(distance < 10){
    isRepeat = true;
  }

  else if(distance >= 10 && distance < 30){
    isRepeat = false;
    isReverse = false;
  }

  else{
    isRepeat = false;
    isReverse = true;    
  }

  if(isRepeat){
    if(isReverse){
      motor.step(-step_level);   
    } else {
      motor.step(step_level);
    }
     step_count++;  

    if(step_count > step_half){
      isReverse = !isReverse;
      step_count = 0;
    }
  } 

  if(!isRepeat && !isReverse){
    motor.step(step_level);
  }

  if(!isRepeat && isReverse){
    motor.step(step_level);
  }
}


long getDistanceFromSensor()
{
  long duration, cm;
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  cm = (duration / 2) / 29.1;

  return cm;
}
