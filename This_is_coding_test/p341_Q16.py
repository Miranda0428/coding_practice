# general rule
# 1. 벽을 3개 세우는 모든 경우의 수에 대해서 안전지대 수의 최대값을 구한다.
# 2. 벽을 세운 후에는 DFS/BFS로 2를 전파시키고 안전지대 수를 센다.
import copy
from collections import deque
import itertools
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
array = [[] * m for _ in range(n)]
for i in range(n):
    array[i] = list(map(int, input().split()))
# n = 7
# m = 7
# array = [[2,0,0,0,1,1,0],
#          [0,0,1,0,1,2,0],
#          [0,1,1,0,1,0,0],
#          [0,1,0,0,0,0,0],
#          [0,0,0,0,0,1,1],
#          [0,1,0,0,0,0,0],
#          [0,1,0,0,0,0,0]]

def find_safezone(mat):
    safezone = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j] == 2:
                dfs(mat, i, j)

    for i in range(n):
        for j in range(m):
            if mat[i][j] == 0:
                safezone += 1

    return safezone

def dfs(mat, x, y):      # 감염시키기
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx > (n - 1) or ny < 0 or ny > (m - 1):
            continue
        if mat[nx][ny] == 0:
            mat[nx][ny] = 2
            dfs(mat, nx, ny)
        else:
            continue

def bfs(mat, x, y):      # 감염시키기

    dx = [0,0,1,-1]
    dy = [1,-1,0,0]

    q = deque()
    q.append((x, y))

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx > (n-1) or ny < 0 or ny > (m-1):
                continue
            if mat[nx][ny] == 0:
                q.append((nx, ny))
                mat[nx][ny] = 2
            else:
                continue

def test():

    conv_mat = []
    array_mat = [[] * m for _ in range(n)]
    max_result = 0

    for i in range(n):
        for j in range(m):
            if array[i][j]==0:
                conv_mat.append((i,j))

    for x in itertools.combinations(conv_mat, 3):
        array_mat=copy.deepcopy(array)
        array_mat[x[0][0]][x[0][1]] = 1
        array_mat[x[1][0]][x[1][1]] = 1
        array_mat[x[2][0]][x[2][1]] = 1
        result = find_safezone(array_mat)
        max_result = max(max_result, result)

    print(max_result)

if __name__ == '__main__':
    test()