# general rule
# 1. d[i] = d[i//5] + 1의 점화식은 i가 5의 배수일 때만 가능하다.
# 2. 리스트를 만들어서 i 인덱스 자리에 d[i] = d[i//5] + 1 또는 d[i] = d[i-1]+1 중에서 작은 값을 삽입한다.

import time

def test():
    n = int(input())
    d = [0] * (n+1)         # 리스트 선언 주의!

    for i in range(2, n+1):
        d[i] = d[i-1] + 1

        if i%5 == 0:
            d[i] = min(d[i], d[i//5]+1)
        if i%3 == 0:
            d[i] = min(d[i], d[i//3]+1)
        if i%2 == 0:
            d[i] = min(d[i], d[i//2]+1)

    return d[n]

if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)