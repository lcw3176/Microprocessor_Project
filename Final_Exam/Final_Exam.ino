#include <MsTimer2.h>

#define led_one 22
#define led_two 23

#define trigger 24
#define echo 25

#define switch_pin 18


volatile bool isBusy = false;

void setup() {
  Serial.begin(9600);
  pinMode(switch_pin, INPUT_PULLUP);
  pinMode(led_one, OUTPUT);
  pinMode(led_two, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(led_one, LOW);
  digitalWrite(led_two, LOW);
  
  attachInterrupt(digitalPinToInterrupt(switch_pin), callBack, CHANGE);

}

void loop() {
 long cm = getDistanceFromSensor();

 if(cm <= 20)
 {
  digitalWrite(led_one, HIGH);
  delay(2000);
  digitalWrite(led_one, LOW);
 }

 else
 {
  digitalWrite(led_one, HIGH);
 }

 delay(2000);
}

void callBack()
{
  int state = digitalRead(switch_pin);
  Serial.println("인터럽트");
  //FALLING
  if(!state && !isBusy)
  {
    isBusy = true;
    digitalWrite(led_two, HIGH);
  }

  if(state && isBusy)
  {
    isBusy = false;
    digitalWrite(led_two, LOW);
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

  Serial.print("distance: ");
  Serial.println(cm);
  return cm;
}
