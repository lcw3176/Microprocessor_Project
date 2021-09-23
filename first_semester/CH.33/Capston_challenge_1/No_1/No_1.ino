
int led = 9;
volatile int state = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(0, blink, FALLING);

}

void loop() {
  digitalWrite(led, state);
}

void blink(){
  state = !state;
}
