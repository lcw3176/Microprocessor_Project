#define ledOne 22
#define ledTwo 24
#define ledThree 26
#define ledFour 28
#define ledFive 30
#define ledSix 32
#define ledSeven 34
#define ledEight 36

const int sampleWindow = 50;
unsigned int sample;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis = millis();
  unsigned int peakToPeak = 0;

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while(millis() - startMillis < sampleWindow){
    sample = analogRead(A1);

    if(sample > signalMax){
      signalMax = sample;
    } else if(sample < signalMin){
      signalMin = sample;
    }
  }

  peakToPeak = signalMax - signalMin;
  double volts = (peakToPeak * 3.3) / 1024;

  if(volts > 1.0){
    for(int i = ledOne; i <= ledEight; i += 2){
      digitalWrite(i, LOW); 
    }
    
    for(int i = ledOne; i <= map(volts, 0, 3.3, ledOne, ledEight); i += 2){
      digitalWrite(i, HIGH);  
    }
  }
}
