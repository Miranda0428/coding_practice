import time

def test():
    start = input()
    #start_x = int(ord(start[0])) - int(ord('a')) + 1
    start_x = ord(start[0]) - ord('a') + 1
    start_y = int(start[1])

    steps = [(-2, 1), (-2, -1), (2, 1), (2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    count = 0
    for step in steps:
        dst_x = start_x + step[0]
        dst_y = start_y + step[1]
        if dst_x >= 1 & dst_y >= 1 & dst_x <= 8 & dst_y <= 8:
            count += 1
            
    print(count)

if __name__ == '__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)