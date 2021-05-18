volatile int count = 0;
const byte interruptPin = 18;

void setup() {
  noInterrupts();
  DDRA = 0xff;
  interrupts();
  attachInterrupt(digitalPinToInterrupt(interruptPin), cnt, HIGH);  
}

void loop() {
  if(count < 5){
    PORTA = 0xff;
  }

  if(count >= 5){
    PORTA = 0x00;
  }

  if(count == 10){
    count = 0;
  }

}

void cnt(){
  count++;
}
