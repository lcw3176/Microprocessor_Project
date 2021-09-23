volatile unsigned char led_state = 0x00;

void setup() {
  cli();
  Serial.begin(9600);
  DDRA = 0x07;  
  DDRD = 0x00;
  
  PORTA = 0x01;

  EIMSK = 0x01;
  EICRA = 0x03;
  sei();
}

void loop() {
  PORTA = led_state;
  delay(2000);

  led_state ^= 0x03;
}

ISR(INT0_vect)
{
  if(led_state & (0x04))
  { 
    led_state ^= 0x04;
  } 

  else
  {
    led_state |= 0x04;
  }

  Serial.println("rising edge");
}
