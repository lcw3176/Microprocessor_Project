#include <FrequencyTimer2.h>

#define M{ \
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 0, 0, 0, 0, 1, 1},\
  {1, 0, 1, 0, 0, 1, 0, 1},\
  {1, 0, 0, 1, 1, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
}

#define E{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}



#define C{ \
  {0, 0, 0, 0, 0, 0, 1, 1},\
  {0, 0, 0, 0, 1, 1, 0, 0},\
  {0, 0, 0, 1, 0, 0, 0, 0},\
  {0, 0, 1, 0, 0, 0, 0, 0},\
  {0, 0, 1, 0, 0, 0, 0, 0},\
  {0, 0, 0, 1, 0, 0, 0, 0},\
  {0, 0, 0, 0, 1, 1, 0, 0},\
  {0, 0, 0, 0, 0, 0, 1, 1},\
}


#define H{ \
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
}


#define A{ \
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {0, 0, 0, 0, 0, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 1, 0, 0, 1, 0, 0},\
  {0, 1, 0, 0, 0, 0, 1, 0},\
  {0, 1, 1, 1, 1, 1, 1, 0},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
}


#define T{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
}


#define R{ \
  {1, 1, 1, 0, 0, 0, 0, 0},\
  {1, 0, 0, 1, 0, 0, 0, 0},\
  {1, 0, 0, 1, 0, 0, 0, 0},\
  {1, 1, 1, 0, 0, 0, 0, 0},\
  {1, 1, 0, 0, 0, 0, 0, 0},\
  {1, 0, 1, 0, 0, 0, 0, 0},\
  {1, 0, 0, 1, 0, 0, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
}

#define O{ \
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 1, 0, 0, 1, 0, 0},\
  {0, 1, 0, 0, 0, 0, 1, 0},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {0, 1, 0, 0, 0, 0, 1, 0},\
  {0, 0, 1, 0, 0, 1, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
}

#define N{ \
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 0, 0, 0, 0, 0, 1},\
  {1, 0, 1, 0, 0, 0, 0, 1},\
  {1, 0, 0, 1, 0, 0, 0, 1},\
  {1, 0, 0, 0, 1, 0, 0, 1},\
  {1, 0, 0, 0, 0, 1, 0, 1},\
  {1, 0, 0, 0, 0, 0, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 1},\
}

#define I{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}

#define S{ \
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 0, 0, 0, 0, 0, 0, 0},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
  {0, 0, 0, 0, 0, 0, 0, 1},\
  {0, 0, 0, 0, 0, 0, 0, 1},\
  {0, 0, 0, 0, 0, 0, 0, 1},\
  {1, 1, 1, 1, 1, 1, 1, 1},\
}

int pin[17] = {-1, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};
int col[8] = {pin[9], pin[10], pin[11], pin[12], pin[13], pin[14], pin[15], pin[16]};
int row[8] = {pin[1], pin[2], pin[3], pin[4], pin[5], pin[6], pin[7], pin[8]};

int colIndex = 0;
byte pattern[12][8][8] = {M, E, C, H, A, T, R, O, N, I, C, S};
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
  patternGenerator(index);
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

  if(index >= 12){
    index = 0;
  }

  patternGenerator(index);
}


void loop() {
  
}
