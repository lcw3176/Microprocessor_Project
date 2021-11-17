#include <FrequencyTimer2.h>

#define I{ \
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {0, 0, 0, 0, 0, 0, 0, 0},\
}

#define N{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {0, 0, 0, 0, 0, 0, 1, 0},\
  {0, 0, 0, 0, 0, 1, 0, 0},\
  {0, 0, 0, 0, 1, 0, 0, 0},\
  {0, 0, 0, 1, 0, 0, 0, 0},\
  {0, 0, 1, 0, 0, 0, 0, 0},\
  {0, 1, 0, 0, 0, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}



#define D{ \
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 1, 0, 0, 1, 0, 0},\
  {0, 1, 0, 0, 0, 0, 1, 0},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}


#define U{ \
  {1, 1, 1, 1, 1, 0, 0, 0},\
  {0, 0, 0, 0, 0, 1, 0, 0},\
  {0, 0, 0, 0, 0, 0, 1, 0},\
  {0, 0, 0, 0, 0, 0, 0, 1},\
  {0, 0, 0, 0, 0, 0, 0, 1},\
  {0, 0, 0, 0, 0, 0, 1, 0},\
  {0, 0, 0, 0, 0, 1, 0, 0},\
  {1, 1, 1, 1, 1, 0, 0, 0},\
}


#define K{ \
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {0, 1, 0, 0, 0, 0, 1, 0},\
  {0, 0, 1, 0, 0, 1, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}


#define M{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {0, 1, 0, 0, 0, 0, 0, 0},\
  {0, 0, 1, 0, 0, 0, 0, 0},\
  {0, 0, 1, 0, 0, 0, 0, 0},\
  {0, 1, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}


#define LOVE{ \
  {0, 1, 1, 1, 0, 0, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
  {0, 1, 0, 0, 0, 1, 0, 0},\
  {0, 0, 1, 0, 0, 0, 1, 0},\
  {0, 0, 1, 0, 0, 0, 1, 0},\
  {0, 1, 0, 0, 0, 1, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
  {0, 1, 1, 1, 0, 0, 0, 0},\
}



int pin[17] = {-1, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};
int col[8] = {pin[9], pin[10], pin[11], pin[12], pin[13], pin[14], pin[15], pin[16]};
int row[8] = {pin[1], pin[2], pin[3], pin[4], pin[5], pin[6], pin[7], pin[8]};

int colIndex = 0;
byte pattern[7][8][8] = {I,N,D,U,K,M,LOVE};
byte LED[8][8] = {0};
int index = 0;
unsigned long mill = 0;

void setup() {
  for(int i = 1; i <= 16; i++){
    pinMode(pin[i], OUTPUT);
  }

  pinMode(18, INPUT_PULLUP);

  initDisplay();
  FrequencyTimer2::setOnOverflow(displayDot);
  attachInterrupt(digitalPinToInterrupt(18), switchPushEvent, FALLING);
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

  for(int i = 0; i < 8; i++){
    if(LED[colIndex][7 - i] == 1){
      digitalWrite(row[i], HIGH);
    }

    else {
      digitalWrite(row[i], LOW);
    }
  }

  digitalWrite(col[colIndex], LOW);
}



void patternGenerator(int idx){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      LED[i][j] = pattern[idx][i][j]; 
    }
  }
}

void switchPushEvent(){
  if(millis() - mill <= 300){
    return;
  }

  mill = millis();
  
  index++;

  if(index >= 7){
    index = 0;
  }

  patternGenerator(index);
}


void loop() {
  
}
