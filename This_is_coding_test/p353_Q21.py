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

def dfs(x, y):
    global visited_list, total
    if (x, y) is visited_list:
        return
    else:
        visited_list.append((x, y))
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >=n:
                continue
            if (nx, ny) in visited_list:
                continue
            if abs(A[x][y]-A[nx][ny]) >= bottom and abs(A[x][y]-A[nx][ny]) <= top:
                dfs(nx, ny)

def solution(n, bottom, top, A):
    global visited_list, total
    visited_list = []
    total = 0
    visited_save = 0
    count = 0
    while A_list:
        visited_save = len(visited_list)
        x = A_list[0][0]
        y = A_list[0][1]
        dfs(x, y)
        if visited_save == len(visited_list) + 1:
            A_list.remove((x, y))
            continue
        else:
            for x, y in visited_list:
                total += A[x][y]
            average = total//len(visited_list)
            for x, y in visited_list:
                A[x][y] = average
            count += 1
            for room in visited_list:
                x, y = room
                if (x, y) in A_list:
                    A_list.remove((x, y))
    return count

print(solution(n, bottom, top, A))