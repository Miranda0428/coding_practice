from collections import deque
INF = 1e9
def solution():
    n, m, k, x = map(int, input().split())
    graph = [[] for _ in range(m+1)]          # node 1과 연결된 node의 갯수가 몇개인지 모를 때 리스트 초기화
    visited = [0] * (n+1)
    distance = [INF] * (n+1)

    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)

    q = []
    q = deque()
    q.append(x)
    distance[x] = 0

    while q:
        now = q.popleft()
        for i in graph[now]:
            if visited[i] == 0:
                visited[i] = 1
                if distance[i] > distance[now] + 1:
                    distance[i] = distance[now] + 1
                    q.append(i)

    for i in range(1, (n+1)):
        if distance[i] == k:
            print(i, end=' ')


if __name__ == '__main__':
    solution()