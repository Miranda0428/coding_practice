# general rule
# 1. 다이나믹 프로그래밍은 점화식을 만들 수 있으면 된다.
# 2. a_i = min(a_(i), a(i-k)+1)

import time

def test():
    n = int(input())
    m = int(input())
    money = list(map(int, input().split()))

    a = [10001] * (m + 1)
    money.sort()

    if money[-1] > m:
        return -1

    for i in money:
        a[i] = 1

    for i in range(money[0]+1, m+1):
        for k in money:
            a[i] = min(a[i], a[i-k] + 1)

    if a[m] == 10001:
        return -1
    return a[m]

if __name__ == '__main__':
    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time - start_time)