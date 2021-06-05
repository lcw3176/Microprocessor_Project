#include <MsTimer2.h>
#include <Servo.h>

#define switch_input 2
#define led 6
#define buzzer 8
#define echo 9
#define trigger 10
#define servoPin 11

int interrupt_count = 0;

int led_pwm = 0;
bool led_pwm_state = true; // true: 정방향 , false: 역방향

bool led_twinkle_state = true;

Servo servo;
int angle = 0;
int maxAngle = 0;
int offset = 0;

int stop_count = 0;
bool buzzer_state = true;


void setup() {
  pinMode(switch_input, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(switch_input), switchEvent, CHANGE);

  servo.attach(servoPin);
  servo.write(angle);

  Serial.begin(9600);

}

void loop() {

}


void switchEvent() {
  int state = digitalRead(switch_input);

  // FALLING
  if (!state)
  {
    if (interrupt_count >= 4)
    {
      interrupt_count = 0;
    }

    interrupt_count++;
    long distance = getDistanceFromSensor();

    if (interrupt_count == 1)
    {
      if (distance < 20)
      {
        MsTimer2::set(10, ledFadeInAndOut);
        MsTimer2::start();
      }

      else
      {
        digitalWrite(led, HIGH);
      }
    }

    if (interrupt_count == 2)
    {
      if (distance < 20)
      {
        MsTimer2::set(2000, ledTwinkle);
        MsTimer2::start();
      }

      else
      {
        digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
      }
    }

    if (interrupt_count == 3)
    {
      if (distance < 20)
      {
        maxAngle = 90;
        offset = 1;
      }

      else
      {
        maxAngle = 180;
        offset = 10;
      }

      MsTimer2::set(500, servoRotation);
      MsTimer2::start();
    }
  }

  // RISING
  if (state && interrupt_count == 4)
  {
    digitalWrite(led, HIGH);
    MsTimer2::set(500, beepBuzzer);
    MsTimer2::start();
  }

}

void beepBuzzer()
{
  stop_count++;
  digitalWrite(buzzer, buzzer_state);
  buzzer_state = !buzzer_state;

  if (stop_count >= 4)
  {
    stop_count = 0;
    MsTimer2::stop();
  }
}

void servoRotation()
{
  servo.write(angle);
  angle += offset;

  if (angle > maxAngle)
  {
    angle = 0;
  }

}

void ledTwinkle()
{
  digitalWrite(led, led_twinkle_state);
  digitalWrite(buzzer, led_twinkle_state);

  led_twinkle_state = !led_twinkle_state;
}

void ledFadeInAndOut()
{
  analogWrite(led, led_pwm);

  if (led_pwm >= 255)
  {
    led_pwm_state = false;
  }

  if (led_pwm <= 0)
  {
    led_pwm_state = true;
  }

  if (led_pwm_state)
  {
    led_pwm++;
  }

  else
  {
    led_pwm--;
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
