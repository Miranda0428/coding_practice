# general rule
# 1. dijkstra simple : 방문하지 않은 노드 중에서, 최단 거리가 가장 짧은 노드 선택 O(v^2)
# 2. dijkstra advanced : 우선순위 큐 라이브러리를 이용해서 속도 향상 O(Elogv)

import time

INF = int(1e9)

def dijkstra_simple():
    n = 6
    m = 11
    start = 1
    graph = [[] for i in range(n+1)]
    graph = [[],[(2,2),(3,5),(4,1)],[(3,3),(4,2)],[(2,3),(6,5)],[(3,3),(5,1)],[(3,1),(6,2)],[]]

    visited = [False] * (n+1)
    distance = [INF] * (n+1)

    # for _ in range(m):
    #     a, b, c = map(int, input().split())
    #     graph[a].append((b, c))

    def get_smallest_node():
        min_value = INF
        index = 0
        for i in range(1, n + 1):
            if distance[i] < min_value and not visited[i]:
                min_value = distance[i]
                index = i
        return index

    distance[start] = 0
    visited[start] = True

    for j in graph[start]:
        distance[j[0]] = j[1]

    for i in range(n-1):
        now = get_smallest_node()
        visited[now] = True
        for j in graph[now]:
            cost = distance[now] + j[1]
            if cost < distance[j[0]]:
                distance[j[0]] = cost

    for i in range(1, n+1):
        if distance[i] == INF:
            print("INFINITY")
        else:
            print(distance[i])

import heapq
def dijkstra_advanced():
    n = 6
    m = 11
    start = 1
    graph = [[] for i in range(n+1)]
    graph = [[],[(2,2),(3,5),(4,1)],[(3,3),(4,2)],[(2,3),(6,5)],[(3,3),(5,1)],[(3,1),(6,2)],[]]

    distance = [INF] * (n+1)

    # for _ in range(m):
    #     a, b, c = map(int, input().split())
    #     graph[a].append((b, c))

    distance[start] = 0

    q = []
    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)
        for j in graph[now]:
            cost = dist + j[1]
            if distance[j[0]] < cost:
                continue
            else:
                distance[j[0]] = cost
                heapq.heappush(q, (cost, j[0]))

    for i in range(1, n+1):
        if distance[i] == INF:
            print("INFINITY")
        else:
            print(distance[i])

if __name__ == '__main__':
    start_time = time.time()
    print(dijkstra_advanced())
    end_time = time.time()
    print("Time : ", end_time - start_time)