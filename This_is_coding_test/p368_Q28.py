# 고정점 찾기
# 이진 탐색(이진 탐색을 하기 위해서는 자료가 정렬된 상태여야 한다.)
n = int(input())
numbers = list(map(int, input().split()))

def solution(start, end):
    while start <= end:
        mid = (end + start)//2
        if mid == numbers[mid]:
            return mid
        elif mid < numbers[mid]:
            end = mid - 1
        else:
            start = mid + 1
    return -1

start = 0
end = n-1
print(solution(start, end))