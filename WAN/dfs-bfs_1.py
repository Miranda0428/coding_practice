
def dfs(graph, v, visited):
    visited[v] = 1
    print(v, end=' ')
    for i in graph[v]:
        if visited[i]==0:
            dfs(graph, i, visited)

from collections import deque
def bfs(graph, v, visited):
    visited[v] = 1
    q = deque()
    q.append(v)

    while q:
        now = q.popleft()
        print(now, end=' ')
        for i in graph[now]:
            if visited[i]==0:
                visited[i] = 1
                q.append(i)

if __name__=='__main__':
    graph = [[], [2, 3, 8], [1, 7], [1, 4, 5], [3, 5], [3, 4], [7], [2, 6, 8], [1, 7]]

    visited = [0] * 9
    dfs(graph, 1 ,visited)

    print(" ")
    
    visited = [0] * 9
    bfs(graph, 1, visited)