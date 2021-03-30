void setup() {
  DDRA = 0x0f;
  PORTA = 0x00;
  
  unsigned char led = 0x01;
  
  while(1){
    if(PINA & 0x10){
      PORTA = led;
      led <<= 1;
      delay(1000);
      if(led == 0x10){
        led = 0x01;
      }
    }
  }
  
}
