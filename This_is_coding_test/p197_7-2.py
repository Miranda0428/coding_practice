# general rule
# 1. 가게 부품번호를 오름차순으로 정렬한다.
# 2. 손님이 준 리스트의 물건번호를 가게 부품번호에서 이진탐색한다.

import time

def test():
    n = input()
    my_list = list(map(int, input().split()))
    guest_list = list(map(int, input().split()))

    list_len = len(my_list)
    my_list.sort()

    for a in guest_list:
        binary_search(my_list, a, 0, list_len-1)
    return

def binary_search(array, target, start, end):       # 이진탐색 코드를 작성해야 할 일이 많으므로 암기
                                                    # 이 경우는 재귀함수 구현. 반복문으로도 구현할 수 있다.
    mid = (start + end)//2

    if(start>end):                                 # if(start>=end): 아님!
        print('no')
        return False

    if target == array[mid]:
        print('yes')
    elif target > array[mid]:
        binary_search(array, target, mid+1, end)
    else:
        binary_search(array, target, start, mid-1)


if __name__=='__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()
    print("Time : ", end_time-start_time)