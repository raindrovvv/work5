# work5
**필수 기능 가이드**

새로운 엑터를 생성하고 엑터가 spawn 되는 시점에 동작되도록 아래 요구사항대로 동작하도록 코드를 구현 합니다

`시작점(0,0)` 있는 게임 캐릭터가 랜덤하게 10회 이동 합니다. 

각 스텝에서 거쳐간 좌표를 모두 출력하는게 목적입니다.

- 시작점은 (0,0)이고 한번 이동 시 x좌표와 y좌표 모두 2이상 이동할 수 없습니다. 예를 들면 아래와 같습니다.
    - (0,0) 에서 (1,2)은 이동할 수 없다. y좌표가 2 이상 이동했기 때문에
    - (0,0)에서 (1,1)은 이동할 수 있다. x좌표  y좌표 모두 2미만 이동했기 때문에
- 이동은 입력을 받는게 아니고 10회 모두 랜덤으로 움직입니다.
- 매번 이동시 현재 좌표를 출력할 수 있어야 합니다.
- 로그 출력은 UE_LOG를 활용합니다.
- step 함수는 x좌표 y좌표 각각 이동할 거리 입니다.
    - 현재 좌표가(x1,y1)이라면 다음 좌표는 (x1+step 함수의 리턴값,y1 + step함수의 리턴 값) 입니다.
    - step함수는 0혹은 1을 랜덤으로 반환 합니다.
- move함수는 (0,0)부터 10회 움직이면서 좌표를 출력합니다. 이동시 step 함수가 활용 됩니다.

#

**도전 기능 가이드** 

필수 기능 구현을 완료한 후 아래 기능을 추가 힙니다.

- 10회 이동시 각 스텝마다 **이전 좌표기준** 이동 거리를 계산해서 출력 합니다.  이동 거리는 아래와 같이 계산 합니다.
    ![image](https://github.com/user-attachments/assets/b06e2b5d-f877-4194-988c-13d3dcb6fbab)
    
- 10회 이동시 각 스텝마다, 50% 확률로 랜덤하게 이벤트가 발생합니다.(발생 시키는 부분도 구현하셔야 합니다.)  각  스텝마다 이벤트 발생여부를 출력합니다.
- 10회 이동후에는 총 이동거리와 총 이벤트 발생횟수를 출력 합니다.

이를 구현한다면 아래와 같은 클래스가 될 것 입니다.(꼭 따라하실 필요는 없고 참조만 하세요)

![image](https://github.com/user-attachments/assets/cc30e52c-c05d-4f9a-bd6f-e977c2cfe3c6)


## 결과
![image](https://github.com/user-attachments/assets/7382efbc-7db9-447c-ab96-4a452f003f79)

