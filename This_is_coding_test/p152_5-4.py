# general rule
# 1. 시작 포인트에서 상하좌우에 있는 포인트에 대해서 1 이고 방문하지 않았으면 큐에 넣는다.
# 2. 더 이상 방문할 포인트가 없으면 큐를 popleft 한다.
# 3. 큐가 빌때까지 수행하고 n-1*m-1 위치에 있는 포인트를 출력한다.

import time
from collections import deque

maze = [[1, 0, 1, 0, 1, 0], [1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1]]
n = 5
m = 6

def test():
    return bfs(0, 0)


def bfs(x, y):
    queue = deque()
    queue.append((0, 0))

    dx = [1,-1,0,0]
    dy = [0,0,1,-1]

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]

            if next_x < 0 or next_x >=n or next_y < 0 or next_y >= m:
                continue
            if maze[next_x][next_y]==0:
                continue
            if maze[next_x][next_y]==1:
                maze[next_x][next_y] = maze[x][y] + 1
                queue.append((next_x, next_y))

    return maze[n-1][m-1]



if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)
