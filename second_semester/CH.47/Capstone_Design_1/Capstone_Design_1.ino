// L298N 모터 드라이버를 사용한다는 전제를 가정함

#define ENA  23 
#define FRONT_RIGHT  24   
#define BACK_RIGHT  25   
#define ENB 26  
#define FRONT_LEFT  27   
#define BACK_LEFT  28   

#define sensor 18

volatile int index = 0;

typedef enum _direction{
  FORWARD,
  RIGHT,
  LEFT,
  BACK,
}DIRECTION;

volatile DIRECTION robotDirection = FORWARD;

void setup() {
  pinMode(sensor, INPUT);
  for(int i = ENA; i <= BACK_LEFT; i++){
    pinMode(i, OUTPUT);
  }
  
  attachInterrupt(digitalPinToInterrupt(sensor), detectEvent, FALLING);
}

void loop() {
  moveRobotCleaner(robotDirection);
}


void detectEvent(){
  index++;

  if(index >= 4){
    index = 0;
  }

  robotDirection = (DIRECTION)index;
}

void moveRobotCleaner(DIRECTION directionToMove){
  switch(directionToMove){
    case FORWARD:
      digitalWrite(ENA, HIGH);
      digitalWrite(FRONT_RIGHT, HIGH);
      digitalWrite(BACK_RIGHT, HIGH);
      
      digitalWrite(ENB, HIGH);
      digitalWrite(FRONT_LEFT, HIGH);
      digitalWrite(BACK_LEFT, HIGH);
      break;
      
    case BACK:
      digitalWrite(ENA, HIGH);
      digitalWrite(FRONT_RIGHT, LOW);
      digitalWrite(BACK_RIGHT, HIGH);
      
      digitalWrite(ENB, HIGH);
      digitalWrite(FRONT_LEFT, LOW);
      digitalWrite(BACK_LEFT, HIGH);
      break;

   case LEFT:
      digitalWrite(ENA, LOW);
      digitalWrite(FRONT_RIGHT, LOW);
      digitalWrite(BACK_RIGHT, LOW);
      
      digitalWrite(ENB, HIGH);
      digitalWrite(FRONT_LEFT, HIGH);
      digitalWrite(BACK_LEFT, LOW);
      break;

   case RIGHT:
      digitalWrite(ENA, HIGH);
      digitalWrite(FRONT_RIGHT, HIGH);
      digitalWrite(BACK_RIGHT, LOW);
      
      digitalWrite(ENB, LOW);
      digitalWrite(FRONT_LEFT, LOW);
      digitalWrite(BACK_LEFT, LOW);
      break;
   default:
      break;
  }
}
