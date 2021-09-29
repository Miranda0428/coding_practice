# general rule
# 0. 위상정렬 알고리즘을 이용한다.
# 1. indegree가 0인 노드 a를 찾아서 큐에 넣는다.
# 2. a와 연결된 간선은 제거하여 연결된 노드의 indegree가 0이면 큐에 삽입한다.
# 3. time[a] += a 수강 소요시간
# 4. 큐에서 노드를 꺼낸다.
# 5. 2로 회귀

import time
from collections import deque

n = 5
def test():
    ltime = [0] * (n+1)
    indegree = [0] * (n+1)
    result = [0] * (n+1)
    graph = [[] for i in range(n+1)]
    q = deque()

    for i in range(1, (n+1)):
        data = list(map(int, input().split()))
        ltime[i] = data[0]
        for j in data[1:-1]:
            graph[j].append(i)
            indegree[i] += 1
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        for node in graph[now]:
            indegree[node] -= 1
            if indegree[node] == 0:
                q.append(node)
                ltime[node] += ltime[now]

    for i in range(1, n+1):
        print(ltime[i])

if __name__ == '__main__':
    start_time = time.time()
    test()
    end_time = time.time()
    print("Time : ", end_time - start_time)