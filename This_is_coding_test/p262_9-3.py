# general rule
# 1. 다익스트라 알고리즘을 이용해서 최단거리를 구한다.
# 2. 연결된 모든 v 갯수와, distance 중에 최대값을 출력한다.

import time

import heapq
INF = int(1e9)

def test():

    # v, e = map(int, input().split())
    v = 3
    e = 2
    start = 1
    graph = [[] for i in range(v+1)]

    for i in range(e):
        x, y, z = map(int, input().split())
        graph[x].append((y, z))

    #graph = [[], [(4, 2), (3, 2)],[],[]]
    distance = [INF] * (v+1)
    distance[start] = 0

    q = []
    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)
        for j in graph[now]:
            cost = dist + j[1]
            if cost > distance[j[0]]:
                continue
            else:
                distance[j[0]] = cost
                heapq.heappush(q, (cost, j[0]))

    country = 0
    max_time = 0

    for i in range(1, v+1):
        if distance[i] == INF or distance[i] == 0 :
            continue
        else:
            country += 1
            max_time = max(max_time, distance[i])

    return country, max_time


if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)