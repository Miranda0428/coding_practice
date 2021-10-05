def recursive_function(i):
    if(i==100):
        print("종료")
        return 0
    print(i, "번째 재귀함수에서", i+1, "번째 재귀함수를 호출합니다.")
    recursive_function(i+1)
    print(i, "번째 재귀함수를 종료합니다.")

def factorial(n):
    if(n >= 1):
        result = n * factorial(n-1)
        return result
    else:
        return 1

graph = [[],[2,3,8],[1,7],[1,4,5],[3,5],[3,4],[7],[2,6,8],[1,7]]
dfs_visited = [False]*9
bfs_visited = [False]*9

def dfs(graph, v, dfs_visited):
    dfs_visited[v] = 1
    print(v, end=' ')
    for i in graph[v]:
        if dfs_visited[i]==False:
            dfs(graph, i, dfs_visited)

from collections import deque

def bfs(graph, start, bfs_visited):
    queue = deque([start])
    bfs_visited[start] = 1

    while queue:
        v = queue.popleft()      # deque 라이브러리의 쓰임을 기억, 맨 처음 들어온 원소를 pop
        print(v, end=' ')
        for i in graph[v]:
            if bfs_visited[i] == False:
                queue.append(i)
                bfs_visited[i] = 1

if __name__=='__main__':

    dfs(graph, 1, dfs_visited)
    print(' ')
    bfs(graph, 1, bfs_visited)
