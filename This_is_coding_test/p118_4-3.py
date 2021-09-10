import time

def test():
    size = list(map(int, input().split()))
    loc_dir = list(map(int, input().split()))

    n = size[0]
    m = size[1]

    array = [[0] * m for _ in range(n)]
    visited = [[0] * m for _ in range(n)]

    for i in range(n):
        array[i] = list(map(int, input().split()))
    print(array)

    # 북쪽을 보고있을 경우 한 칸 이동
    new_loc_dir = loc_dir + [0, -1, 1]

    # 동쪽을 보고있을 경우 한 칸 이동
    new_loc_dir = loc_dir + [1, 0, 1]

    # 남쪽을 보고있을 경우 한 칸 이동
    new_loc_dir = loc_dir + [0, 1, 1]

    # 서쪽을 보고있을 경우 한 칸 이동
    new_loc_dir = loc_dir + [-1, 0, -3]

    count = 0
    turn_time = 0

    while True:
        visited[loc_dir[0], loc_dir[1]] = 1
        if loc_dir[2]==1:
            new_loc_dir = loc_dir + [0, -1, 1]
            i, j = new_loc_dir[0], new_loc_dir[1]
            if (visited[i, j]==0) & (array[i, j]==0):
                loc_dir = new_loc_dir
                visited[i, j] = 1
                count += 1
                continue
            elif (visited[i, j]==1):
                loc_dir += [0, 0, 1]
                turn_time += 1


if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)