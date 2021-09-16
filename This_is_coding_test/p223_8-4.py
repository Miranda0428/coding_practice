# general rule
# 1. 다이나믹 프로그래밍은 점화식을 만들 수 있으면 된다.
# 2. a_i = a_(i-1) + a(i-2)*2

import time

def test():
    n = int(input())
    a = [0] * (n+1)

    a[1] = 1
    a[2] = 3

    for i in range(3, n + 1):
        a[i] = a[i-1] + a[i-2] * 2

    return a[n]


if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)