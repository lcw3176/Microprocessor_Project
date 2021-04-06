void TurnOnLed(bool isReverse, bool isPersistent, int rotateCount);

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
  int sw1Pushed = digitalRead(26);
  int sw2Pushed = digitalRead(27);
  int sw3Pushed = digitalRead(28);
  int sw4Pushed = digitalRead(29);
  
    if(sw1Pushed)
    {
      TurnOnLed(false, false, 3);
    }

    if(sw2Pushed)
    {
       TurnOnLed(true, false, 2);
    }
    
    if(sw3Pushed)
    {
      TurnOnLed(false, true, 3);
    }
    
    if(sw4Pushed)
    {
      TurnOnLed(true, true, 2);
    }
}


void TurnOnLed(bool isReverse, bool isPersistent, int rotateCount){

  for(int i = 0; i < rotateCount; i++)
  {
    if(isReverse)
    {
      for(int j = 25; j >= 22; j--)
      {
         digitalWrite(j, HIGH);
         delay(500);

         digitalWrite(j, isPersistent);
      }
    }

    else
    {
      for(int j = 22; j <= 25; j++)
      {
        digitalWrite(j, HIGH);
        delay(500);
    
        digitalWrite(j, isPersistent);
      }
    }


    for(int k = 22; k <= 25; k++)
    {
      digitalWrite(k, LOW);
    }

    delay(500);
  }
}
