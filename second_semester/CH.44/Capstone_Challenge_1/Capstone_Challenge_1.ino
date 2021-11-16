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
  for(int i = ledOne; i <= ledEight; i += 2){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  analogReference(EXTERNAL); // 3.3v 사용
}

void loop() {
  unsigned long startMillis = millis();
  unsigned int peakToPeak = 0;

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while(millis() - startMillis < sampleWindow){
    sample = analogRead(A0);

    if(sample > signalMax){
      signalMax = sample;
    } else if(sample < signalMin){
      signalMin = sample;
    }
  }

  peakToPeak = signalMax - signalMin;
  double volts = (peakToPeak * 3.3) / 1024;
  int volume = (volts / 3.3) * 100; // 편하게 100단위로 변경

  if(volume > 5){
    volume *= 2; // 임의로 볼륨 증폭

    Serial.println(volume);
    for(int i = ledEight; i >= ledOne; i -= 2){
      digitalWrite(i, LOW); 
    }
    
    for(int i = ledOne; i <= map(volume, 0, 100, ledOne, ledEight); i += 2){
      digitalWrite(i, HIGH);  
    }
  } else{
    for(int i = ledEight; i >= ledOne; i -= 2){
      digitalWrite(i, LOW); 
    }
  }
}
