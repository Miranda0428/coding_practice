Wrong Answer Note

**리스트 초기화**
- 삼성 SW 아카데미 D1 홀수만 더하기
- 1차 배열([0,0,...,0]) 초기화 list = [0] * n
- 2차 배열(m * n) 초기화 list = [[0] * n for i in range(m)]

**DFS/BFS 코드 암기**
- 교재 기출 Q16 연구소 / 백준 14502
- import itertools 을 사용했다. 사용불가능하다면 어떻게 구현해야 할 것인가?
- DFS로 구현한다면 더 빨랐을까? yes 약간 빠름
- p118_4-3_1 : 게임 개발

**sort**
- 선택/삽입/퀵/계수 sort
- p359_Q23
- data.sort(key=lambda x: (-int(x[1]),int(x[2]),-int(x[3]),x[0]))
- sort에서의 lambda 사용...sort의 기준 함수인데 두번째 원소를 기준으로 reverse 이면서~ 세번째 원소를 기준으로 정렬이면서~ 로 해석
- 즉, 맨 처음 나오는 조건을 최우선으로 하고 그 조건이 유지되는 상황에서 두번째 나오는 조건을 기준으로 정렬

**search**
- 이진탐색
- p201_7-3_1 : 떡볶이 자르기

**map**
- map(int, input().split())은 띄어쓰기로 구분되는 input에 대해서 모두 int 함수를 적용한다는 뜻
