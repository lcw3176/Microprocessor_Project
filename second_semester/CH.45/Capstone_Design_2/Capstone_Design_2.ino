#include <SPI.h>
#include <MFRC522.h>
#include <TimerOne.h>

#define RST_PIN 49
#define SS_PIN 53
#define maxUser 2
#define uidMaxSize 10 


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
byte uidArr[maxUser][uidMaxSize] = {-1};
volatile int displayInfo = -1;
String displayStr = "";

void setup() {
  for(int i = 22; i <= 33; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  SPI.begin();

  mfrc522.PCD_Init();
  Timer1.initialize(10000); 
  Timer1.attachInterrupt(display_fnd);
  
  ShowReaderDetails();
  Serial.println("Scan PICC to see UID, type, and data blocks...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()){
    return;
  }

  if(!isFull){
    registerUser();
  } else {
    int userInfo = getUserInfo();
    
    displayInfo = userInfo;
    Serial.print(userInfo);
    Serial.print("번 ");
    Serial.print(displayStr);
    Serial.println("사용자의 카드입니다.");
  }
}

void registerUser(){
  char index = userCount;

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
    displayInfo = userCount - 1;
  } else{
    Serial.print(userCount);
    Serial.println("번 사용자 등록 완료");
    displayInfo = userCount;
  }

  
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


void display_fnd(){
  String sentence = "";
  
  switch(displayInfo){
    case 1:
      sentence = "apple";
      break;
    case 2:
      sentence = "banana";
      break;
    case 3:
      sentence = "mango";
      break;
    case 4:
      sentence = "orange";
      break;
    default:
      sentence = "none";
      break;
  }

  displayStr = sentence;

   digitalWrite(seg1,LOW);
   charfnd(sentence[0]);
   delay(1);
   digitalWrite(seg1,HIGH);
   
   digitalWrite(seg2,LOW);
   charfnd(sentence[1]);
   delay(1);
   digitalWrite(seg2,HIGH);
   
   digitalWrite(seg3,LOW);
   charfnd(sentence[2]);
   delay(1);
   digitalWrite(seg3,HIGH);
   
   digitalWrite(seg4,LOW);
   charfnd(sentence[3]);
   delay(1);
   digitalWrite(seg4,HIGH);
}

void charfnd(char spell) // 문자 출력 함수
{
 switch(spell)
 {
   case 'a':
     //Displays A
     digitalWrite(ledD, LOW);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, HIGH);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, HIGH);
     digitalWrite(ledC, HIGH);
     digitalWrite(DOT , LOW);
     break;
     
   case 'b':
     //Displays B
     digitalWrite(ledD, HIGH);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, HIGH);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, HIGH);
     digitalWrite(ledC, HIGH);
     digitalWrite(DOT , LOW);
     break;
     
   case 'c':
     //Displays C
     digitalWrite(ledD, HIGH);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, LOW);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, LOW);
     digitalWrite(ledC, LOW);
     digitalWrite(DOT , LOW);
     break;
     
   case 'd':
     //Display D
     digitalWrite(ledD, HIGH);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, LOW);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, HIGH);
     digitalWrite(ledC, HIGH);
     digitalWrite(DOT , LOW);
     break;
     
   case 'e':
    //Displays E
     digitalWrite(ledD, HIGH);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, HIGH);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, LOW);
     digitalWrite(ledC, LOW);
     digitalWrite(DOT , LOW);
     break;
     
   case 'f':
     //Displays F
     digitalWrite(ledD, LOW);
     digitalWrite(ledE, HIGH);
     digitalWrite(ledF, HIGH);
     digitalWrite(ledG, HIGH);
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, LOW);
     digitalWrite(ledC, LOW);
     digitalWrite(DOT , LOW);
     break;
     
   case 'g':
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;
    
   case 'n':
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
    
   case 'p':
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;
    
   case 'o':
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
    
   case 'l':
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
   default:
    break;
   }
}
