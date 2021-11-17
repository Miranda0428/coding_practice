**다시 풀어야할 문제**

최대 상금, 공통 조상, 최적 경로 문제는 메모이제이션으로 다시


**문자열 숫자를 정수형 숫자로**

![image](https://user-images.githubusercontent.com/17174701/141229136-f972a47c-bee9-4ead-831f-1d42404d73fc.png)


**2차원 배열을 함수 매개별수로 전달하기**

2차원 배열 arr[100][100]을 함수 인자로 전달하기 위해서는 char arr[][100] 또는 char (*arr)[100] 으로 전달해야 한다.


**재귀호출을 이용한 완전탐색(최대 상금)**

순열 조합 문제는 이것으로 해결 가능, 결국은 dfs!!

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
  
 ![image](https://user-images.githubusercontent.com/17174701/142149908-6eead60e-905f-4542-a8c1-773e0445a5cf.png)

  
  **가중치가 있는 완전탐색(최적 경로)**


정말 고민을 많이 한 문제가 최적 경로 문제이다.

재귀호출로 완전탐색을 구현하는 것은 결국 dfs를 하는 것이고,

최적 경로를 찾는 것은 가중치의 합 중에 최소인 값을 찾는 것이다.

![image](https://user-images.githubusercontent.com/17174701/141939330-27644c7c-a9c2-484e-9891-2486124f7f00.png)


for 문위에 int ret = INF;를 쓰지 않아 하루종일 고민했다.

company가 root이고 home이 말단 노드라고 보면된다.

첫번째 탐색에서 첫번째 갈림길은 company→1→2→3→4→5→home 와 company→1→2→3→5→4→home 이다. 첫번째 경로와 두번째 경로 모두 home까지 갔다가 결과값을 올려준다.

그 결과값은 3에서 만나고 ret에는 첫번째 경로의 결과 그리고 tmp에는 두번째 경로의 결과가 들어있다.

즉, 갈림길에서 갈려서 올라온 결과값들이 비교된 것이고, 갈림길(3)을 만나기 전까진 ret = INF 이다.

타고 올라가다 보면 마지막 갈림길은 company가 되고 그 때 num_customer개의 결과 값 중 가장 작은 값이 최종 ret 값이다.

**고속화를 위해서는 메모이제이션을 한다.**

**가중치가 없는 그래프에서는 bfs로 최단 경로를 구할 수 있다.**
  

**메모이제이션(최적 경로)**
  
  1. #include<memory>를 해주고 memo[N][N]을 전역변수로 선언
  
  2. main에서 memset(arr, 0x00, sizeof(arr))로 초기화
  
  3. 재귀함수에서 레퍼런스 변수로 memo를 지정하고 연산해야 하는 결과가 memo에 있으면 그 값을 리턴한다.
  (ret = INF 선언이 지역변수에서 전역으로 바뀌었다. 잊지말자.)
  
  ![image](https://user-images.githubusercontent.com/17174701/142144210-d8ece9c2-8e0e-435a-97c2-adee47edfd29.png)


