import time

# general한 rule을 먼저 발견한다.
# 그것을 코드로 구현한다.

# general rule
# 1. 모든 점을 돌면서 방문하지 않았다면 2을 수행하고 카운트를 하나 올린다
# 2. 방문 포인트를 방문처리하고 상하좌우에 대하여 방문하지 않았다면 dfs 검색

def test():

    global ice_cube
    ice_cube = [[0,0,1,1,0],[0,0,0,1,1],[1,1,1,1,1],[0,0,0,0,0]]
    global n
    n = 4
    global m
    m = 5
    global visited
    visited = [[0] * m for _ in range(n)]

    count = 0

    for i in range(n):
        for j in range(m):
            if ice_cube[i][j] == 0 and visited[i][j] == 0:
                dfs(i, j)
                count += 1
            else:
                continue
    return count

def dfs(x, y):
    if x < 0 or x >= n or y < 0 or y >= m or (visited[x][y] == 1):
        return False
    else:
        if(ice_cube[x][y] == 0):
            visited[x][y] = 1
            dfs(x-1, y)
            dfs(x+1, y)
            dfs(x, y-1)
            dfs(x, y+1)






if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print(end_time-start_time)
