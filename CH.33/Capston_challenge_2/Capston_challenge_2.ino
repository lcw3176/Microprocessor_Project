#include <MsTimer2.h>

#define switch_input 18
#define led_red 22
#define led_blue 23
#define buzzer 24

bool led_state = true;

void setup() {
  pinMode(switch_input, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(switch_input), switchEvent, CHANGE);

  MsTimer2::set(2000, ledEvent);
  MsTimer2::start();

}

void loop() {

}

void switchEvent() {
  
  if(digitalRead(switch_input))
  {
    digitalWrite(buzzer, LOW);
  }

  else
  {
    digitalWrite(buzzer, HIGH);
  }
  
}

void ledEvent(){
  digitalWrite(led_red, led_state);
  digitalWrite(led_blue, !led_state);
  led_state = !led_state;
}
