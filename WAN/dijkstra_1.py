# general rule
# 1. dijkstra simple : 방문하지 않은 노드 중에서, 최단 거리가 가장 짧은 노드 선택 O(v^2)
# 2. dijkstra advanced : 우선순위 큐 라이브러리를 이용해서 속도 향상 O(Elogv)

import time

INF = int(1e9)

def setting(tuples):
    return tuples[1]

def get_small_node(list):
    list.sort(key=setting)
    return list[0]


def dijkstra_simple():
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

    for i in graph[start]:
        distance[i[0]] = i[1]

    for node in range(1, n-1):
        small = get_small_node(graph[node])

        for i in graph[small[0]]:
            new_dis = distance[small[0]] + i[1]
            if distance[i[0]] > new_dis:
                distance[i[0]] = new_dis

    print(distance[1:])

import heapq
def dijkstra_advanced():
    n = 6
    m = 11
    start = 1
    graph = [[] for i in range(n+1)]
    graph = [[],[(2,2),(3,5),(4,1)],[(3,3),(4,2)],[(2,3),(6,5)],[(3,3),(5,1)],[(3,1),(6,2)],[]]
    distance = [INF] * (n+1)

    q = []

    # for _ in range(m):
    #     a, b, c = map(int, input().split())
    #     graph[a].append((b, c))

    distance[start] = 0
    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)
        for i in graph[now]:
            # if visited[i[0]] == 0:
            #     visited[i[0]] = 1
            new_dis = i[1] + dist
            if distance[i[0]] > new_dis:
                distance[i[0]] = new_dis
                heapq.heappush(q, (new_dis, i[0]))

    print(distance[1:])

if __name__ == '__main__':
    start_time = time.time()
    dijkstra_simple()
    dijkstra_advanced()
    end_time = time.time()
    print("Time : ", end_time - start_time)