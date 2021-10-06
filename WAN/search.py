def binary_search(array, target, start, end):
    if start > end:
        return None
    mid = (start + end)//2
    if array[mid] == target:
        return mid
    elif array[mid] < target:
        return binary_search(array, target, mid+1, end)
    else:
        return binary_search(array, target, start, mid-1)

import sys
if __name__ == '__main__':
    #array = [1,3,5,7,9,11,13,15,17,19]
    array = list(map(int, sys.stdin.readline().rstrip().split()))
    target = 7
    print(binary_search(array, target, 0, 9))