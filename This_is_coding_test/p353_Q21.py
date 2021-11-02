# 인구 이동
# 푸는데 시간이 정말 많이 걸렸다. 7~8시간 걸린 듯
# 오래걸린 원인 :
# 1. 문제를 잘못이해했음
# 2. deepcopy를 하지 하고 얕은 복사를 해서 원하는 결과를 얻지 못함
# 3. move 라는 flag 기능을 생각해내지 못함
# 이 문제는 꼭 다시 풀어봐야 한다.
n, bottom, top = map(int, input().split())
A = []
A_list = []
for i in range(n):
    A.append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):
        A_list.append((i, j))

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def dfs(x, y, visited_list, A):
    global total
    if (x, y) in visited_list:
        return
    else:
        visited_list.append((x, y))
        total += A[x][y]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if abs(A[x][y]-A[nx][ny]) >= bottom and abs(A[x][y]-A[nx][ny]) <= top:
                dfs(nx, ny, visited_list, A)
    return total

import copy
def solution(n, bottom, top, A, A_list):
    global total
    count = 0
    move = 1
    visited_list = []
    new_A = copy.deepcopy(A)
    new_A_list = copy.deepcopy(A_list)
    while move:
        move = 0
        A = copy.deepcopy(new_A)
        A_list = copy.deepcopy(new_A_list)
        while A_list:
            total = 0
            visited_list.clear()
            x = A_list[0][0]
            y = A_list[0][1]
            total = dfs(x, y, visited_list, A)

            if len(visited_list) <= 1:
                new_A[x][y] = A[x][y]
                A_list.remove((x, y))
            else:
                average = total // len(visited_list)
                for (x, y) in visited_list:
                    new_A[x][y] = average
                    A_list.remove((x, y))
                if move != 1:
                    move = 1
                    count += 1
    return count

print(solution(n, bottom, top, A, A_list))