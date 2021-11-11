211109

**문자열 숫자를 정수형 숫자로**

for (int j = 0; j < col; ++j) {
			if (tmp[j] >= 'A')          
				a = tmp[j] - 'A' + 10;
			else
				a = tmp[j] - '0';


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
  
  **메모이제이션**

