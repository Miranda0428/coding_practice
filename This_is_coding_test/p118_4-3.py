import time

def turn_left(dir):
    if dir == 3:
        return 0
    return (dir + 1)


def test():

    #size = list(map(int, input().split()))
    #loc_dir = list(map(int, input().split()))

    #n = size[0]
    #m = size[1]

    #array = [[0] * m for _ in range(n)]
    #visited = [[0] * m for _ in range(n)]

    #for i in range(n):
        #array[i] = list(map(int, input().split()))
    #print(array)

    size = [4, 4]
    loc_dir = [1, 1, 0]
    array = [[0] * 4 for _ in range(4)]
    visited = [[0] * 4 for _ in range(4)]

    array = [[1,1,1,1],[1,0,0,1],[1,1,0,1],[1,1,1,1]]

    # 서쪽으로 한 칸 이동 loc_dir + [0, -1]
    # 남쪽으로 한 칸 이동 loc_dir + [1, 0]
    # 동쪽으로 한 칸 이동 loc_dir + [0, 1]
    # 북쪽으로 한 칸 이동 loc_dir + [-1, 0]

    count = 1     # 시작위치 count
    turn_time = 0

    start_x = loc_dir[0]
    start_y = loc_dir[1]
    start_dir = loc_dir[2]
    visited[start_x][start_y] = 1
    steps = [[-1, 0],[0, 1],[1, 0],[0, -1]]

    while True:
        dir = turn_left(start_dir)
        turn_time += 1
        next_x = start_x + steps[dir][0]
        next_y = start_y + steps[dir][1]
        start_dir = dir

        if(array[next_x][next_y]==1) | (visited[next_x][next_y]==1):
            if (turn_time == 4):
                next_x = start_x - steps[dir][0]
                next_y = start_y - steps[dir][1]
                if(array[next_x][next_y]==0):
                    start_x = next_x
                    start_y = next_y
                    turn_time = 0
                else:
                    break
            continue
        else:
            start_x = next_x
            start_y = next_y
            visited[next_x][next_y] = 1
            turn_time = 0
            count += 1
    return count

if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)
