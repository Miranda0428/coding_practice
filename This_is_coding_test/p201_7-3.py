# general rule
# 1. 시작점을 0으로 가장 긴 떡의 길이를 끝점으로 해서 손님이 원하는 길이가 나올때까지 이진탐색한다.
# 2. 손님이 원하는 길이가 나올때 중간점을 리턴한다.

import time

def test():
    #n, m = map(int, input().split())
    #dduck = list(map(int, input().split()))

    n = 4
    m = 6
    dduck = [19, 15, 10, 17]

    dduck.sort()

    return binary_search(dduck, m, 0, dduck[n-1])

def binary_search(array, max_len, start, end):       # 이진탐색 반복문으로 구현

    n = len(array)
    tmp = []
    while True:
        if start > end:
            return False
        else:
            mid = (start + end)//2
            for i in range(n):
                if array[i] > mid:
                    tmp.append((array[i]-mid))
                else:
                    continue
            sum_tmp = sum(tmp)
            tmp.clear()
            if sum_tmp == max_len:
                return mid
            elif sum_tmp > max_len:
                start = mid + 1
            else:
                end = mid - 1

if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)