# Microprocessor_Project
챌린지 소스코드 관리

### 예상 진행 기간
* 21.03 ~ 21.07

### 개발 환경
* MicroController: ATmega2560
* IDE: Sketch

### 학기말 프로젝트
#### Who_Are_You
누군가 이 기계가 부착된 문이나 서랍을 열면 알람을 보내주는 장치(사진 전송도 계획중, 될지는 모르겠다.)
#### 필요한 부품
* MC-38 자석 센서
* HC-06 블루투스 센서
* ESP8266 와이파이 모듈
* 카메라 모듈 (계획)
#### 개발 환경
* 서버: Java Spring [WhoAreYou_Spring](https://github.com/lcw3176/WhoAreYou_Spring)
* 어플리케이션: C# Xamarin [WhoAreYou_Xamarin](https://github.com/lcw3176/WhoAreYou_Xamarin)
* DB: MySQL
<details>
<summary>user 테이블</summary>
<div markdown="1">
<pre>
<code>

    create table user(
    idx int primary key auto_increment,
    email varchar(40) not null unique,
    password varchar(64) not null
    );

</pre>
</code>
</div>
</details>

<details>
<summary>device 테이블</summary>
<div markdown="1">
<pre>
<code>

  create table device(
  idx int primary key auto_increment,
  name varchar(30) not null,
  user_idx int,
  foreign key(user_idx)
  references user(idx)
  on update cascade
  on delete cascade);

</pre>
</code>
</div>
</details>

<details>
<summary>log 테이블</summary>
<div markdown="1">
<pre>
<code>

  create table log(
  idx int primary key auto_increment,
  time timestamp on update current_timestamp default current_timestamp not null,
  state int not null,
  device_idx int,
  foreign key(device_idx)
  references device(idx)
  on update cascade
  on delete cascade);

</pre>
</code>
</div>
</details>

#### 작동 방식
1. 어플을 통해 회원가입을 한다.
2. 블루투스를 통해 장치와 연결 후, 와이파이 연결을 세팅한다.
3. 자석이 떨어지면 장치는 서버로 알림을 보내고, 해당 유저에게 전송한다.(WebSocket)
4. 유저의 핸드폰에 등록된 Notification을 통해 알람이 울린다.