#include <LiquidCrystal.h>
#define rowSize 2 
#define colSize 16

LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

char firstSentence[] = "KOREA Fighting!";
char secondSentence[] = "Induk University!";

void setup() {
  lcd.begin(colSize, rowSize);
}

int i = 0;

void loop() {
  
  lcd.setCursor(i - 1, 0);
  lcd.print(' ');
  lcd.setCursor(i, 0);
  lcd.print(firstSentence);

  lcd.setCursor(colSize - i - 1 + (sizeof(secondSentence) / sizeof(char) - 1), 1);
  lcd.print(' ');    
  lcd.setCursor(colSize - i - 1, 1);
  lcd.print(secondSentence);

  delay(100);
  i++;

  if(i > colSize * 2)
  {
    i = 0;
  }
}
