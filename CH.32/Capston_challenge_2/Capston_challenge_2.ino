#include <LiquidCrystal.h>
#define rowSize 2 
#define colSize 16
#define firstSize sizeof("KOREA Fighting!") / sizeof(char) - 1
#define secondSize sizeof("Induk University!") / sizeof(char) - 1

LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

int len = 0;
int cursorCol = 0;
int cursorRow = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(colSize, rowSize);
}


void loop() {
  char* data;
  
  if(Serial.available())
  {
    len = Serial.available();
    
    data = (char *)malloc(sizeof(char) * len);
    Serial.readBytes(data, len); 
    Serial.println(data);
    
    for(int i = 0; i < len; i++)
    {
      lcd.setCursor(cursorCol + i, cursorRow);
      lcd.print(data[i]);
      delay(100);
    }


    cursorCol += len;

    if(cursorRow == 0 && cursorCol >= firstSize)
    {
      cursorRow += 1;
      cursorCol = 0;
    }

    if(cursorRow == 1 && cursorCol >= secondSize)
    {
      cursorRow -= 1;
      cursorCol = 0;
      lcd.clear();
    }
    
    free(data);
  }


}
