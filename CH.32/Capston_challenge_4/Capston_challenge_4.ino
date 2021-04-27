#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcdOne(0x27, 16, 2);
LiquidCrystal_I2C lcdTwo(0x26, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcdOne.init();
  lcdTwo.init();
//  find_address();
}

bool isRun = false;

void loop() {
  
  if(Serial.available())
  {
     delay(100);
     int len = Serial.available();
     char* words = (char *)malloc(sizeof(char) * len);
     Serial.readBytes(words, len);

     Serial.println(words);
     lcdOne.setCursor(0, 0);
     lcdOne.print(words);

     lcdOne.setCursor(0, 1);
     lcdOne.print(words);  

     lcdTwo.setCursor(16, 0);
     lcdTwo.print(words);

     lcdTwo.setCursor(16, 1);
     lcdTwo.print(words);     

     isRun = true;
  }

  if(isRun)
  {
    lcdOne.scrollDisplayRight();
    lcdTwo.scrollDisplayLeft();
    delay(100);
  }
}

void find_address()
{
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
  // end of setup
}
