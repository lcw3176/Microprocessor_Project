#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <MsTimer2.h>

#define buzzer 22
volatile long cnt = 0;
bool buzzer_state = true;
char buzzer_count = 0;

LiquidCrystal lcd(23, 24, 25, 26, 27, 28);

void setup() {
  pinMode(buzzer, OUTPUT);   
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  Timer1.initialize(200);
  Timer1.attachInterrupt(counterCallBack);
  
  Serial.begin(9600);
}

void counterCallBack()
{
  cnt++;

  if(cnt % 10000 == 0)
  {
    Serial.println(cnt);
    MsTimer2::set(500, buzzerBeep);
    MsTimer2::start();
  }
}

void buzzerBeep()
{
  buzzer_count++;
  digitalWrite(buzzer, buzzer_state);
  buzzer_state = !buzzer_state;

  if(buzzer_count >= 2)
  {
    Serial.println("buzzer stop");
    buzzer_count = 0;
    MsTimer2::stop();
  }
}

void loop() {
//  Serial.println(cnt);
  lcd.print(cnt);
  lcd.setCursor(0, 0);
 
}
