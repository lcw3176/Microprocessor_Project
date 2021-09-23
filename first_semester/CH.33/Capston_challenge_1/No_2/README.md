# CH.33
## HIGH, RISING, CHANGE 비교 및 차이점
---
### CHANGE
![change](https://user-images.githubusercontent.com/59993347/118611318-aa7c2580-b7f7-11eb-9379-1a5a6be228ef.gif)
* 버튼 상태가 바뀔 때 마다 인터럽트 발생
* LOW -> HIGH, HIGH -> LOW 
* 한번 누를 때마다 2번의 인터럽트 발생
---
### HIGH
![high](https://user-images.githubusercontent.com/59993347/118611320-abad5280-b7f7-11eb-8d44-51ac9cf70ce4.gif)
* PULL-DOWN 회로 기준 시 버튼을 누르고 있으면 계속 발생
* HIGH~~~
* 버튼을 누르고 있으면 계속해서 인터럽트 발생
---
### RISING
![rising](https://user-images.githubusercontent.com/59993347/118611322-abad5280-b7f7-11eb-9b3f-d2c097f5a75c.gif)
* PULL-DOWN 회로 기준 시 버튼을 누를 때 마다 발생 
* LOW -> HIGH 상태가 될 때 발생
* 한번 누를 때마다 1번의 인터럽트 발생
