n = int(input())
school = []
for _ in range(n):
    school.append(list(input().split()))

X_list = []
T_list = []
S_list = []

for i in range(n):
    for j in range(n):
        if school[i][j] == 'X':
            X_list.append((i, j))
        if school[i][j] == 'T':
            T_list.append((i, j))
        if school[i][j] == 'S':
            S_list.append((i, j))

def dfs(x, y, O, dir):
    # global 변수 check가 어떻게 쓰이고 있는 지 주의하자.
    # 여기서 global check 선언을 안해주면 다른 결과가 나온다.
    # dfs에서 check = 1을 만들었어도 global check를 선언 안하면 다시 0이 된다.
    global check
    if x < 0 or y < 0 or x >= n or y >= n:
        return
    if (x, y) in O:
        return
    if (x, y) in S_list:
        check = 1
        return
   # 한 방향으로만 dfs를 실행시키기 위해서 방향을 변수로 추가하였다.
    if dir == 1:
        dfs(x - 1, y, O, 1)
    if dir == 2:
        dfs(x + 1, y, O, 2)
    if dir == 3:
        dfs(x, y - 1, O, 3)
    if dir == 4:
        dfs(x, y + 1, O, 4)

from collections import deque
from itertools import combinations
O_list = deque(combinations(X_list, 3))

O = O_list.popleft()
while True:
    global check
    check = 0
    for T in T_list:
        x, y = T
        dfs(x, y, O, 1)
        dfs(x, y, O, 2)
        dfs(x, y, O, 3)
        dfs(x, y, O, 4)
    if check:
        if O_list:
            O = O_list.popleft()
        else:
            print("NO")
            break
    else:
        print("YES")
        break