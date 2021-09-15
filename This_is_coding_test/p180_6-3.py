# general rule
# 1. 학생의 (이름, 점수)를 입력받는다.
# 2. 점수를 기준으로 정렬한다.

import time

def test():
    n = int(input())
    array = [[0] * 2 for _ in range(n)]
    result = []
    for i in range(n):
        data = input().split()
        array[i][0] = str(data[0])
        array[i][1] = int(data[1])

    array = sorted(array, key=setting)   # sort(6-2 문제 참조)와 sorted의 쓰임을 암기

    for pair in array:
        result.append(pair[0])
    return result

def setting(a):
    return a[1]

if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)
