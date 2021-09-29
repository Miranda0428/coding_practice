# general rule
# 1. 플로이드 워셜 알고리즘 문제
# 2. 2차원 테이블을 만들어서 최단거리를 구한다.

import time

INF = int(1e9)

def test():
    v = 5
    e = 7
    graph = [[INF,INF,INF,INF,INF,INF],[INF,INF,1,1,1,INF],
             [INF,1,INF,INF,1,INF], [INF,1,INF,INF,1,1],
             [INF,1,1,1,INF,1], [INF,INF,INF,1,1,INF]]
    _x = 4
    _k = 5

    for i in range(1, v+1):
        graph[i][i] = 0

    for k in range(1, v+1):
        for a in range(1, v+1):
            for b in range(1, v+1):
                graph[a][b] = min(graph[a][b], (graph[a][k]+graph[k][b]))

    distance = graph[1][_k] + graph[_k][_x]

    if distance == INF:
        print(-1)
    else:
        print(distance)

if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)