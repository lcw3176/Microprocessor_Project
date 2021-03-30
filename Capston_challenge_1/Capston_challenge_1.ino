void turn_on_led(bool isReverse, bool led_existing, int rotate_count);

void setup() {
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);

  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);

}

void loop() {
  int sw1_pushed = digitalRead(26);
  int sw2_pushed = digitalRead(27);
  int sw3_pushed = digitalRead(28);
  int sw4_pushed = digitalRead(29);
  
    if(sw1_pushed)
    {
      turn_on_led(false, false, 3);
    }

    if(sw3_pushed)
    {
      turn_on_led(false, true, 3);
    }
    
    if(sw2_pushed)
    {
       turn_on_led(true, false, 2);
    }

    if(sw4_pushed)
    {
      turn_on_led(true, true, 2);
    }
}


void turn_on_led(bool isReverse, bool led_existing, int rotate_count){

  for(int i = 0; i < rotate_count; i++)
  {
    if(isReverse)
    {
      for(int j = 25; j >= 22; j--)
      {
         digitalWrite(j, HIGH);
         delay(500);

         digitalWrite(j, led_existing);
      }
    }

    else
    {
      for(int j = 22; j <= 25; j++)
      {
        digitalWrite(j, HIGH);
        delay(500);
    
        digitalWrite(j, led_existing);
      }
    }


    for(int k = 22; k <= 25; k++)
    {
      digitalWrite(k, LOW);
    }

    delay(500);
  }
}
