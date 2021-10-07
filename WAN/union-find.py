def find_parent(parent, x):
    if parent[x] != x:
        find_parent(parent, parent[x])
    else:
        return x

def union_parent(parent, a, b):
    pa = find_parent(parent, a)
    pb = find_parent(parent, b)

    if pa < pb:
        parent[b] = pa
    elif pa > pb:
        parent[a] = pb

def cycle_or_not():

    v = 3
    e = 3
    e = [(1,2), (1,3), (2,3)]
    parent = [0] * (v+1)

    cycle = False

    for i in range(1, v+1):
        parent[i] = i

    for i in e:
        a, b = i[0], i[1]
        if find_parent(parent, a)==find_parent(parent, b):
            cycle = True
        else:
            union_parent(parent, a ,b)

    if cycle:
        print("Cycle")
    else:
        print("None")

if __name__ == '__main__':
    cycle_or_not()


