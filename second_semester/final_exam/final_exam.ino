#include <FrequencyTimer2.h>



int pin[17] = {-1, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};
int col[8] = {pin[9], pin[10], pin[11], pin[12], pin[13], pin[14], pin[15], pin[16]};
int row[8] = {pin[1], pin[2], pin[3], pin[4], pin[5], pin[6], pin[7], pin[8]};

int colIndex = 0;
byte LED[8][8] = {0};
int index = 0;
unsigned long mill = 0;
bool isReverse = true;

void setup() {
  for(int i = 1; i <= 16; i++){
    pinMode(pin[i], OUTPUT);
  }


  initDisplay();
  FrequencyTimer2::setOnOverflow(displayDot);
}

void loop() {
  if(millis() - mill <= 1000){
    return;
  }

  mill = millis();

  index++;

  if(index > 8){
    index = 0;
    isReverse = !isReverse;
  }

}

void initDisplay(){
  for(int i = 0; i < 8; i++){
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

void displayDot(){
  digitalWrite(col[colIndex], HIGH);
  colIndex++;

  if(colIndex == 8){
    colIndex = 0;
  }

  if(isReverse){
    for(int i = 7; i > 7 - index; i--){
      digitalWrite(row[i], HIGH);
    }
  
    for(int i = 7 - index; i >= 0; i--){
      digitalWrite(row[i], LOW);
    }
  } else {
    for(int i = 0; i < index; i++){
      digitalWrite(row[i], HIGH);
    }
  
    for(int i = index; i < 8; i++){
      digitalWrite(row[i], LOW);
    }  
  }


  digitalWrite(col[colIndex], LOW);
}
