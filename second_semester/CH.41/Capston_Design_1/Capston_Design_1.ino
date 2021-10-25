#include <DS1302.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>

#define rowSize 2 
#define colSize 16

#define CLK 22
#define DAT 24
#define RST 26

DS1302 rtc(RST, DAT, CLK);
LiquidCrystal lcd(27, 28, 29, 30, 31, 32);

int interruptPin = 18;
enum Mode {
  timeOnly,
  dateOnly,
  DOWOnly,
};

int state = timeOnly;
int index = 0;
void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);

//  rtc.setDOW(FRIDAY);        
//  rtc.setTime(12, 49, 0);     
//  rtc.setDate(24, 9, 2021);   
  lcd.begin(colSize, rowSize);
  lcd.setCursor(0, 0);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(displayClock);
  attachInterrupt(digitalPinToInterrupt(interruptPin), modeChangeEvent, RISING);  
}


void displayClock()
{
  lcd.setCursor(0, 0);
  
  switch(state)
  {
    case timeOnly:
      lcd.print(rtc.getTimeStr());
      break;
    case dateOnly:
      lcd.print(rtc.getDOWStr());
      break;
    case DOWOnly:
      lcd.print(rtc.getDateStr());
      break;
    default:
      break;
  }

  
}


void modeChangeEvent()
{
  lcd.clear();
  index++;

  if(index >= 3)
  {
    index = 0;
  }
  
  state = index;
}

void loop()
{

}
