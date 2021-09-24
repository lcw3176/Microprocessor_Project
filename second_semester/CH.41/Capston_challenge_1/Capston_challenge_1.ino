#include <DS1302.h>

#define CLK 22
#define DAT 24
#define RST 26

DS1302 rtc(RST, DAT, CLK);

void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  
//  rtc.setDOW(FRIDAY);        
//  rtc.setTime(12, 16, 0);     
//  rtc.setDate(24, 9, 2021);  
}

void loop()
{
  Serial.println("-----------------");
  Serial.print("Today is ");
  Serial.println(rtc.getDOWStr());
  
  Serial.println("-----------------");
  Serial.print("Date is ");
  Serial.println(rtc.getDateStr());

  Serial.println("-----------------");
  Serial.print("Time is ");
  Serial.println(rtc.getTimeStr());
  delay (1000);
}
