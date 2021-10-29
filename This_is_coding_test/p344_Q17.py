# 연구소
from collections import deque
def solution(n, k, s, square):
    tmp_q = []
    for i in range(n):
        for j in range(n):
            if square[i][j] != 0:
                tmp_q.append((square[i][j], 0, i, j))

    # 문제를 자의적으로 해석하지 말고 다양한 경우에 대해서도 고려해서 general한 code를 작성해야 한다.
    # virus를 기준으로 오름차순으로 큐가 차있다는 보장이 없다.
    # 따라서 꼭 sort를 해주어야 한다.
    # TC에 매몰되어서는 안된다.
    tmp_q.sort()
    q = deque(tmp_q)

    dx = [0,0,1,-1]
    dy = [1,-1,0,0]

    while q:
        virus, cnt, x, y = q.popleft()
        if cnt == s:
            break
        else:
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= n:
                    continue
                elif square[nx][ny] == 0:
                    square[nx][ny] = virus
                    q.append((virus, cnt + 1, nx, ny))
                else:
                    continue

if __name__ == "__main__":
    n, k = map(int, input().split())
    square = []
    for i in range(n):
        square.append(list(map(int, input().split())))
    s, x, y = map(int, input().split())

    solution(n, k, s, square)
    print(square[x-1][y-1])