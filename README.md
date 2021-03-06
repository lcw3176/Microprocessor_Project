# Microprocessor_Project
챌린지 소스코드 관리

<details>
<summary>1학기</summary>

### 개발 환경
* MicroController: ATmega2560
* IDE: Sketch
* Interrupt / Timer, I2C
* LCD, WiFi, Bluetooth

### 진행 기간
* 21.03 ~ 21.07

## Team Project (Who Are You)
### 장치 설명
- 누군가 이 기계가 부착된 문이나 서랍을 열면 알람을 보내주는 장치

### 작동 영상
- https://www.youtube.com/watch?v=a5a6oeBi8YY
### 필요한 부품
* MC-38 자석 센서
* HC-06 블루투스 센서
* ESP8266 ESP-01 와이파이 모듈

### 개발 환경
* 서버: Java Spring [WhoAreYou_Spring](https://github.com/lcw3176/WhoAreYou_Spring)
* 어플리케이션: C# Xamarin [WhoAreYou_Xamarin](https://github.com/lcw3176/WhoAreYou_Xamarin)
* 임베디드: C++ ATmega2560 [WhoAreYou_ATmega2560](https://github.com/lcw3176/WhoAreYou_ATmega2560)

### 작동 방식
1. 어플을 통해 회원가입을 한다.
2. 블루투스를 통해 장치와 연결 후, 와이파이 연결을 세팅한다.
3. 자석이 떨어지면 장치는 서버로 알림을 보내고, 해당 유저에게 전송한다.(WebSocket)
4. 유저의 핸드폰에 등록된 Notification을 통해 알람이 울린다.

</details>

## 2학기
### 개발 환경
* MicroController: ATmega2560
* IDE: Sketch
* RTC Module, Step Motor, Sound Sensor, Joystick Sensor, RFID, Dot Matrix, IR Sensor

### 예상 진행 기간
* 21.09 ~ 21.12

## Team Project (Guitar Reader)
### 장치 설명
- 기타를 연주하면 음계 분석 후 기록하는 장치

### 작동 영상
- https://www.youtube.com/watch?v=zB0uJF3MIWw

### 필요한 부품
- 사운드 센서 (OPA344 모듈)

### 개발 환경
- 응용 프로그램: C# WPF [GuitarReader_Cs](https://github.com/lcw3176/GuitarReader_Cs)
- 임베디드: C++ ATmega2560 [GuitarReader_Atmega2560](https://github.com/lcw3176/GuitarReader_Atmega2560)

### 작동 방식
1. 센서(OPA344) 를 근처에 위치시킨 후 기타를 연주한다
2. 아두이노에서 센서로 들어온 소리를 분석한다
3. 해당하는 주파수를 응용 프로그램에게 넘겨준다 (Serial 통신)
4. 프로그램에서 해당하는 음계와 기타 줄의 위치를 분석 후, 저장한다

