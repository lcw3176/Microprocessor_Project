# CH.33
내부 Pull-up 저항 스위치 이용, 타이머 및 인터럽트 처리
### 작동 모습
![작동](https://user-images.githubusercontent.com/59993347/120276353-8a675e80-c2ed-11eb-8071-05b0f84106aa.gif)
* 타이머 2초 설정, LED 바꿔가며 점등
* 인터럽트 CHANGE 모드 적용, 버튼 누를 때만 Buzzer 작동

### AVR_Version
* INT0 인터럽트 사용, Pull-Down 저항 사용
* CHANGE를 못써서 불편하다.
* 눌릴 때 마다 부저 키고 끄는 방식으로 바꿈
* EICRB, INT7 ~ INT4로 이사가면 기존 로직과 같은 맥락으로 작성 가능할 듯 하다.
