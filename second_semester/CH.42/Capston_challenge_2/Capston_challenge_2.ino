#include<Stepper.h>

#define IN1 24
#define IN2 26
#define IN3 28
#define IN4 30

#define echo 8
#define trigger 9

#define led_one 32
#define led_two 34
#define led_three 36

Stepper motor(64, IN1, IN3, IN2, IN4);
int step_half = 16;
int step_count = 0;
int step_level = 64;

bool isReverse = false;
bool isRepeat = false;

void setup() {
  Serial.begin(9600);

  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  for(int i = IN1; i <= led_three; i+=2){
    pinMode(i, OUTPUT);
  }

  motor.setSpeed(300);
}

void loop() {
  long distance = getDistanceFromSensor();
  Serial.println(distance);

  if(distance < 10){
    isRepeat = true;
    
    display_led(led_one);
  }

  else if(distance >= 10 && distance < 30){
    isRepeat = false;
    isReverse = false;
    
    display_led(led_two);
  }

  else{
    isRepeat = false;
    isReverse = true; 

    display_led(led_three);   
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
    motor.step(-step_level);
  }
}

void display_led(int pos)
{
  for(int i = led_one; i <= led_three; i++){
    digitalWrite(i, LOW);
  }

  digitalWrite(pos, HIGH);
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
