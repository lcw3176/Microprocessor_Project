#include <Servo.h>

#define X_PIN A0
#define Y_PIN A1

#define SERVO_ONE 8
#define SERVO_TWO 9

#define LED_LEFT 34
#define LED_MOST_LEFT 35
#define LED_MID 36
#define LED_MOST_RIGHT 37
#define LED_RIGHT 38

#define ledA 32
#define ledB 28
#define ledC 25
#define ledD 23
#define ledE 22
#define ledF 31
#define ledG 26
#define DOT 24
#define seg1 33
#define seg2 30
#define seg3 29
#define seg4 27

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

void display_fnd(int number){
   digitalWrite(seg1,LOW);
   fnd(number / 1000);
   delay(5);
   digitalWrite(seg1,HIGH);
   
   digitalWrite(seg2,LOW);
   fnd(number / 100);
   delay(5);
   digitalWrite(seg2,HIGH);
   
   digitalWrite(seg3,LOW);
   fnd(number % 100 / 10);
   delay(5);
   digitalWrite(seg3,HIGH);
   
   digitalWrite(seg4,LOW);
   fnd(number % 100 % 10);
   delay(5);
   digitalWrite(seg4,HIGH);
}

void generate_x(int value){
  int mapped_pin = map(value, 0, 1000, LED_LEFT, LED_RIGHT);

  for(int i = LED_LEFT; i <= LED_RIGHT; i++){
    digitalWrite(i, LOW); 
  }

  digitalWrite(mapped_pin, HIGH);
}


void generate_y(int value){
  int mapped_number = map(value, 0, 1000, 0, 9);
  
  display_fnd(mapped_number);
}

Servo servo_one;
Servo servo_two;

void setup() {
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(SERVO_ONE, OUTPUT);
  pinMode(SERVO_TWO, OUTPUT);

  servo_one.attach(SERVO_ONE);
  servo_two.attach(SERVO_TWO);

  for(int i = ledE; i <= LED_RIGHT; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  digitalWrite(LED_MID, HIGH);
  display_fnd(4);
 
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
