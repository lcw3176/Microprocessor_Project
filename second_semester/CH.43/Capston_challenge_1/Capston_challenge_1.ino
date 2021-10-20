#include <Servo.h>

#define X_PIN A0
#define Y_PIN A1

#define SERVO_ONE 11
#define SERVO_TWO 12

#define LED_LEFT 22
#define LED_MOST_LEFT 23
#define LED_MID 24
#define LED_MOST_RIGHT 25
#define LED_RIGHT 26

#define ledA 27
#define ledB 28
#define ledC 29 
#define ledD 30
#define ledE 31 
#define ledF 32 
#define ledG 33
#define DOT 34


void fnd(int n) // 숫자 출력 함수
{
 switch(n)
 {
   case 0:
   //Displays 0
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, HIGH);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, LOW);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 1:
   //Displays 1
   digitalWrite(ledD, LOW);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, LOW);
   digitalWrite(ledG, LOW);
   digitalWrite(ledA, LOW);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 2:
   //Displays 2
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, HIGH);
   digitalWrite(ledF, LOW);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, LOW);
   digitalWrite(DOT , LOW);
   break;
  
   case 3:
   //Displays 3
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, LOW);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 4:
   //Displays 4
   digitalWrite(ledD, LOW);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, LOW);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 5:
   //Displays 5
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, LOW);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 6:
   //Displays 6
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, HIGH);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, LOW);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
   case 7:
   //Displays 7
   digitalWrite(ledD, LOW);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, LOW);
   digitalWrite(ledG, LOW);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 8:
   //Displays 8
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, HIGH);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;
  
   case 9:
   //Displays 9
   digitalWrite(ledD, HIGH);
   digitalWrite(ledE, LOW);
   digitalWrite(ledF, HIGH);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   digitalWrite(DOT , LOW);
   break;

 }
}

void generate_x(int value){
  Serial.println(value);
  int mapped_pin = map(value, 0, 1000, LED_LEFT, LED_RIGHT);
  Serial.println(mapped_pin);
  for(int i = LED_LEFT; i <= LED_RIGHT; i++){
    digitalWrite(i, LOW); 
  }

  digitalWrite(mapped_pin, HIGH);
}

void generate_y(int value){
  int mapped_number = map(value, 0, 1023, 0, 9);
  
  fnd(mapped_number);
}

Servo servo_one;
Servo servo_two;

void setup() {
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);

  servo_one.attach(SERVO_ONE);
  servo_two.attach(SERVO_TWO);

  for(int i = LED_LEFT; i <= DOT; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  digitalWrite(LED_MID, HIGH);
  fnd(4);
 
}

void loop() {
  int analog_x_value = analogRead(X_PIN);
  int analog_y_value = analogRead(Y_PIN);

  int servo_x_value = map(analog_x_value, 0, 1023, 0, 180);
  int servo_y_value = map(analog_y_value, 0, 1023, 0, 180);

  servo_one.write(servo_x_value);
  servo_two.write(servo_y_value);

  generate_x(analog_x_value);
  generate_y(analog_y_value);
}
