void setup() {
  DDRA = 0x04;
  PORTA = 0x00;
  unsigned char countOne = 0;
  unsigned char countTwo = 0;
  bool isOne = false;
  bool isTwo = false;
  
  while(1)
  {
    if(PINA & 0x01)
    {
      countOne++;
      delay(1000);
      
      if(countOne >= 3)
      {
        isOne = true;
        isTwo = false;
      }

    }

    if(PINA & 0x02)
    {
      countTwo++;
      delay(1000);
      if(countTwo >= 3)
      {
        isTwo = true;
        isOne = false;
      }
    }

    if(isOne)
    {
      PORTA = 0x04;
      delay(1000);
      PORTA = 0x00;
      delay(1000);
    }

    if(isTwo)
    {
      PORTA = 0x04;
      delay(2000);
      PORTA = 0x00;
      delay(2000);
    }


    
  }
}
