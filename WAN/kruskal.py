# 가장 적은 비용으로 모든 노드를 연결하는 알고리즘
# 최소신장트리 찾기
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
        cost, a, b = edge
        pa = find_parent(parent, a)
        pb = find_parent(parent, b)
        if pa != pb:
            result += cost
            union_parent(parent, a, b)

    print(result)

if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)