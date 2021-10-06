# n, m = map(int, input().split())
# x, y, dir = map(int, input().split())

n = 4
m = 4
array = [[1,1,1,1],[1,0,0,1],[1,1,0,1],[1,1,1,1]]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

visited = [[0] * (m) for _ in range(n)]

def tern_left(dir):
    if dir == 3:
        return 0
    else:
        return dir + 1

def test(x, y, dir):

    visited[x][y]=1
    count = 0
    result = 1

    while True:
        if count == 4:
            x = x - dx[dir]
            y = y - dy[dir]
            break
        dir = tern_left(dir)
        count += 1
        nx = x + dx[dir]
        ny = y + dy[dir]
        if nx < 0 or nx >= m or ny < 0 or ny >= n:
            continue
        elif array[nx][ny]== 0 and visited[nx][ny] == 0:
            visited[nx][ny] = 1
            x = nx
            y = ny
            count = 0
            result += 1
        else:
            continue

    print(result)


if __name__=='__main__':
    x = 1
    y = 1
    dir = 0
    test(x, y, dir)