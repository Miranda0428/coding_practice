# general rule
# 1. A 배열에서 가장 작은 값과 B 배열에서 가장 큰 값을 비교해서 min_A가 max_B 보다 크면 바꾼다.

import time

def test():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    A.sort()
    B.sort(reverse=True)

    for i in range(k):                 # for i in A: 아님!
        if A[i] < B[i]:
            A[i], B[i] = B[i], A[i]    # swap
        else:
            break

    return sum(A)                      # A list 원소의 합



if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)