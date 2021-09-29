# general rule
# 1. 최소신장트리를 찾는다.
# 2. 가장 유지비가 많이드는 간선을 제거한다.

import time

# n, m = map(int, input().split())
n = 7
m = 12
parent = [0] * (n + 1)

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

def test():
    edges = []
    result = 0
    last = 0
    for i in range(1, n+1):
        parent[i] = i

    # for i in range(m):
    #     a, b, cost = map(int, input().split())
    #     edges.append((cost, a, b))

    edges = [(3,1,2),(2,1,3),(1,3,2),(2,2,5),(4,3,4),(6,7,3),(5,5,1),(2,1,6),(1,6,4),(3,6,5),(3,4,5),(4,6,7)]

    edges.sort()

    for edge in edges:
        if find_parent(parent, edge[1]) != find_parent(parent, edge[2]):
            union_parent(parent, edge[1], edge[2])
            result += edge[0]
            last = edge[0]
        else:
            continue

    print(result - last)


if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)