#include <SPI.h>
#include <MFRC522.h>
#include <TimerOne.h>

#define RST_PIN 49
#define SS_PIN 53
#define maxUser 2
#define uidMaxSize 10 // 라이브러리 까보니까 4, 7, 10 중 하나라고 써져 있음.

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



MFRC522 mfrc522(SS_PIN, RST_PIN);
bool isFull = false;
int userCount = 0;
int uidArr[maxUser][uidMaxSize] = {-1};
volatile int displayNumber = 0;

void setup() {
  for(int i = 22; i <= 33; i++){
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600);
  SPI.begin();

  mfrc522.PCD_Init();
  
  ShowReaderDetails();
  Serial.println("Scan PICC to see UID, type, and data blocks...");

   Timer1.initialize(10000); 
   Timer1.attachInterrupt(display_fnd);
    
}

void loop() {
  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()){
    if(!isFull){
      registerUser();
    } else {
      displayNumber = getUserInfo();
      Serial.print(displayNumber);
      Serial.println("번 사용자의 카드입니다.");
    }
  }
}

void registerUser(){
  int index = userCount;

  // uid 중복 등록 여부 체크
  if(index != 0){
    bool isSame = true;
    
    for(int i = 0; i < index; i++){
      
       for(byte j = 0; j < mfrc522.uid.size; j++){
        if(uidArr[i][j] != mfrc522.uid.uidByte[j]){
          isSame = false;
          break; 
        }
       }

       if(!isSame){
        break;
       }
    }

    if(isSame){
      Serial.println("이미 등록된 사용자입니다.");
      return;
    }
  }
  
  for(byte i = 0; i < mfrc522.uid.size; i++){
    uidArr[index][i] = mfrc522.uid.uidByte[i];
  }

  userCount++;

  if(userCount > maxUser){
    isFull = true;
    Serial.println("사용자 등록 종료");
  } else{
    Serial.print(userCount);
    Serial.println("번 사용자 등록 완료");
  }

  displayNumber = userCount;
}

int getUserInfo(){
  for(int i = 0; i < maxUser; i++){
    bool isSame = true;
    
    for(byte j = 0; j < mfrc522.uid.size; j++){
      if(uidArr[i][j] != mfrc522.uid.uidByte[j]){
        isSame = false;
        break;
      }
    }

    if(isSame){
      return i + 1;
    }
  }

  return 0;
}

void ShowReaderDetails() {
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  
  Serial.print("MFRC522 Software Version: 0x");
  Serial.print(v, HEX);
 
  if (v == 0x91){
    Serial.print(" = v1.0");
  } else if (v == 0x92){
    Serial.print(" = v2.0");
  } else {
    Serial.print(" (unknown)");
  }
  
  Serial.println("");

  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println("WARNING: Communication failure, is the MFRC522 properly connected?");
  }
}

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

void display_fnd(){
   digitalWrite(seg1,LOW);
   fnd(displayNumber / 1000);
   delay(5);
   digitalWrite(seg1,HIGH);
   
   digitalWrite(seg2,LOW);
   fnd(displayNumber / 100);
   delay(5);
   digitalWrite(seg2,HIGH);
   
   digitalWrite(seg3,LOW);
   fnd(displayNumber % 100 / 10);
   delay(5);
   digitalWrite(seg3,HIGH);
   
   digitalWrite(seg4,LOW);
   fnd(displayNumber % 100 % 10);
   delay(5);
   digitalWrite(seg4,HIGH);
}
