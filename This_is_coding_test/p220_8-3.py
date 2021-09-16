# general rule
# 1. 다이나믹 프로그래밍은 점화식을 만들 수 있으면 된다.
# 2. a_i = max(a_(i-1), a(i-2)+i번째 칸의 식량)

import time

def test():
    n = int(input())
    food = list(map(int, input().split()))
    a = [0] * (n+1)

    a[1] = food[0]                                # food가 1개 일때
    a[2] = max(food[0], food[1])                  # food가 2개 일때
    
    for i in range(3, n+1):
        a[i] = max(a[i-1], a[i-2] + food[i-1])

    return a[n]

if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)