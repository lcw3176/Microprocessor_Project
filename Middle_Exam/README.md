# Middle_Exam
중간고사
#### 고찰
- 급하게 하느라 count 변수들 초기화를 빼먹었다.
- bool 자료형 변수들 초기화할때 같이 초기화 해주는편이 더 좋은 코드인것 같다.

#### 기존 코드
```c
      if(countOne >= 3)
      {
        isOne = true;
        isTwo = false;
      }

```

#### 개선 코드
```c
      if(countOne >= 3)
      {
        isOne = true;
        isTwo = false;
        countOne = 0;
      }

```