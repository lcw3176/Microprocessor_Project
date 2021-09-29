#define X_PIN A0
#define attack_button 18
#define jump_button 20

enum x_movement{
   LEFT,
   STOP,
   RIGHT
};

void attack_event(){
  // attack_motion
}

void jump_event(){
  // jump_motion
}

int now_state = STOP;

void setup() {
  pinMode(X_PIN, INPUT);
  pinMode(attack_button, INPUT_PULLUP);
  pinMode(jump_button, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(attack_button), attack_event, FALLING);
  attachInterrupt(digitalPinToInterrupt(jump_button), jump_event, FALLING);
}

void loop() {
  int state = map(analogRead(X_PIN), 0, 1023, LEFT, RIGHT);

  if(state != now_state){
    now_state = state;

    switch(now_state){
      case LEFT:
        // move_left
        break;
      case STOP:
        // stop_move
        break;
      case RIGHT:
        // move_right
      default:
        break;
  
    }
  }
  

}
