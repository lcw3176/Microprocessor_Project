#include <stdlib.h>

enum{
  one = 0x06, // 0000 0110
  two = 0x5b, //0101 1011
  three = 0x4f, // 0100 1111
  four = 0x66, // 0110 0110
  five = 0x6d, // 0110 1101
  six = 0x7d, // 0111 1101
  seven = 0x27, // 0010 0111
  eight = 0x7f, // 0111 1111
  nine = 0x67, // 0110 0111
  zero = 0x3f // 0011 1111
};

// 7 segment 숫자 디스플레이 함수
void display_number(unsigned char number);

void setup() {

  DDRC = 0x7f; // 7 segment
  DDRA = 0x0f; // led
  DDRB = 0x00; // input_switch
  
  PORTA = 0x00;
  unsigned char seed_count = 0;
  unsigned char is_run = 0;
  unsigned char temp = 0x00;
  
  
  display_number(0);
  
    while(1){
      seed_count++;
      
      if(PINB & 0x01){
        is_run = !is_run;
        srand(seed_count);
        seed_count = 0;
        PORTA = 0x00;
        delay(500);
      }

      if(is_run){
        temp = rand() % 10;
        display_number(temp);
        delay(500);
      }


      if(!is_run){
        PORTA = temp;
      }
    }
}


void display_number(unsigned char number){
  switch(number){
    case 0:
      PORTC = zero;
      break;

    case 1:
      PORTC = one;
      break;

    case 2:
      PORTC = two;
      break;

    case 3:
      PORTC = three;
      break;

    case 4:
      PORTC = four;
      break;

    case 5:
      PORTC = five;
      break;

    case 6:
      PORTC = six;
      break;

    case 7:
      PORTC = seven;
      break;
      
    case 8:
      PORTC = eight;
      break;
      
    case 9:
      PORTC = nine;
      break;

   default:
      break;
    
  }
}
