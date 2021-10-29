# 연산자 끼워 넣기 - dfs
import time
n = int(input())
# 연산을 수행하고자 하는 수 리스트
data = list(map(int, input().split()))
# 더하기, 빼기, 곱하기, 나누기 연산자 개수
add, sub, mul, div = map(int, input().split())

# 최솟값과 최댓값 초기화
min_value = 1e9
max_value = -1e9
total = 0
# 깊이 우선 탐색 (DFS) 메서드
def dfs(i, total, add, sub, mul, div):
    global min_value, max_value
    # 모든 연산자를 다 사용한 경우, 최솟값과 최댓값 업데이트
    if i == n:
        min_value = min(min_value, total)
        max_value = max(max_value, total)
    else:
        # 순서 1. 첫 연산자가 + 로 시작하는 경우부터 깊이 탐색
        if add:
            dfs(i + 1, total + data[i], add-1, sub, mul, div)
        # 순서 2. 첫 연산자가 - 로 시작하는 경우부터 깊이 탐색
        if sub:
            dfs(i + 1, total - data[i], add, sub-1, mul, div)
        # 순서 3. 첫 연산자가 * 로 시작하는 경우부터 깊이 탐색
        if mul:
            dfs(i + 1, total * data[i], add, sub, mul-1, div)
        # 순서 4. 첫 연산자가 / 로 시작하는 경우부터 깊이 탐색
        if div:
            dfs(i + 1, int(total / data[i]), add, sub, mul, div-1)

# DFS 메서드 호출
start = time.time_ns()

dfs(1, data[0], add, sub, mul, div)
# 최댓값과 최솟값 차례대로 출력
print(max_value)
print(min_value)

end = time.time_ns()
print("TIME :", end-start)