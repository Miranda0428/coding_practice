211109

**문자열 숫자를 정수형 숫자로**

![image](https://user-images.githubusercontent.com/17174701/141229136-f972a47c-bee9-4ead-831f-1d42404d73fc.png)

**2차원 배열을 함수 매개별수로 전달하기**

2차원 배열 arr[100][100]을 함수 인자로 전달하기 위해서는 char arr[][100] 또는 char (*arr)[100] 으로 전달해야 한다.

211111

**완전탐색 재귀호출 암기**

순열 조합 문제는 이것으로 해결 가능

연산자 5개로 만들수 있는 가장 큰 수 찾기 

카드 swap해서 최대수 찾기 등에 활용이 많이됨

첫번째 것을 선택하고 안하고/ 두번째 것을 선택하고 안하고....기억

int solve(num, cnt){

  int ret = 0;
  
  if(cnt == 0) return ret;
  
  for(int i=0; i<end; ++i)
  
    solve(f(num), cnt-1);
  
  return ret;
  
  } 와 같은 형식
  
  ![image](https://user-images.githubusercontent.com/17174701/141229254-839012ca-e695-46e7-9678-0201815dd448.png)

  
  **메모이제이션**

