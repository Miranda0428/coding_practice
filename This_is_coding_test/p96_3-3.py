import time

def test():

    #n, m, k = map(int, input().split())
    #data = list(map(int, input().split()))
    n, m = 2, 4
    data = [[7, 3, 1, 8], [3, 3, 3, 4]]

    result = 0

    for i in range(n):
        if result < min(data[i]):
            result = min(data[i])

    return result

if __name__ == '__main__':.

    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)
