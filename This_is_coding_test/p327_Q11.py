# 뱀
def turn_right(dir):
    if dir==3:
        dir = 0
    else:
        dir += 1
    return dir

def turn_left(dir):
    if dir==0:
        dir = 3
    else:
        dir -= 1
    return dir

from collections import deque
def solution(mat_size, apples, turns):
    mat = [[0 for _ in range(mat_size)] for _ in range(mat_size)]

    for apple in apples:
        mat[apple[0]-1][apple[1]-1] = 1

    tail = deque()
    pre_T = 0
    dir = 0
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    head_x = 0
    head_y = 0
    time = 0
    tail.append((0, 0))
    for T in turns:
        k = int(T[0]) - pre_T
        pre_T = int(T[0])
        for i in range(1, k+1):
            head_x += dx[dir]
            head_y += dy[dir]
            if(head_x < 0 or head_x >= mat_size or head_y < 0 or head_y >= mat_size or mat[head_x][head_y]==2):
                return time + 1
            elif(mat[head_x][head_y]==1): # 사과면
                mat[head_x][head_y] = 2
                tail.append((head_x, head_y))
                time += 1
            else:
                mat[head_x][head_y] = 2
                tail.append((head_x, head_y))
                time += 1
                tail_x, tail_y = tail.popleft()
                mat[tail_x][tail_y] = 0

        if T[1] == 'D':
            dir = turn_right(dir)
        else:
            dir = turn_left(dir)

    while True:
        head_x += dx[dir]
        head_y += dy[dir]
        if (head_x < 0 or head_x >= mat_size or head_y < 0 or head_y >= mat_size or mat[head_x][head_y] == 2):
            return time + 1
        elif (mat[head_x][head_y] == 1):  # 사과면
            mat[head_x][head_y] = 2
            tail.append((head_x, head_y))
            time += 1
        else:
            mat[head_x][head_y] = 2
            tail.append((head_x, head_y))
            time += 1
            tail_x, tail_y = tail.popleft()
            mat[tail_x][tail_y] = 0

if __name__=="__main__":
    # mat_size_1 = 6
    # apples_1 = [(3, 4), (2, 5), (5, 3)]
    # turn_1 = [(3, 'D'), (15, 'L'), (17, 'D')]
    #
    # mat_size_2 = 10
    # apples_2 = [(1, 2), (1, 3), (1, 4), (1, 5)]
    # turn_2 = [(8, 'D'), (10, 'D'), (11, 'D'), (13, 'L')]
    #
    # mat_size_3 = 10
    # apples_3 = [(1, 5), (1, 3), (1, 2), (1, 6), (1, 7)]
    # turn_3 = [(8, 'D'), (10, 'D'), (11, 'D'), (13, 'L')]

    mat_size = int(input())
    apple_num = int(input())
    apples = []
    turns = []
    for apple in range(apple_num):
        apples.append(list(map(int, input().split())))        # map(int, input().split()) 으로 하면 나중에 list 연산을 할 수 없음!
    turn_time = int(input())
    for turn in range(turn_time):
        turns.append(input().split())

    print(solution(mat_size, apples, turns))