# general rule
# 1. union - find 문제
# 2. parent가 같으면 YES 아니면 NO

import time

n, m = map(int, input().split())
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

    for i in range(1, n+1):
        parent[i] = i

    for i in range(m):
        oper, a, b = map(int, input().split())

        if(oper == 0):
            union_parent(parent, a, b)
        else:
            if find_parent(parent, a)==find_parent(parent, b):
                print("YES")
            else:
                print("NO")


if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)