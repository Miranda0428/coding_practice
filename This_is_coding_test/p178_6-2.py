# general rule
# 1. 숫자를 입력받아 리스트를 만든다.
# 2. 리스트를 sort() 함수를 이용하여 정렬한다.

import time

def test():
    n = int(input())
    array = [0] * n
    for i in range(n):
        array[i] = int(input())
    array.sort()
    array.reverse()
    return array

if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)
