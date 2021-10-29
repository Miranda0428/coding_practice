# 정렬된 배열에서 특정 수의 개수 구하기
def solution():
    n, m = map(int, input().split())
    data = list(map(int, input().split()))

    start = 0
    end = n-1

    while True:
        if start > end:
            return -1
        mid = (start+end)//2
        if m == data[mid]:
            break
        elif m < data[mid]:
            end = mid - 1
        else:
            start = mid + 1

    i = mid
    count = 0
    while data[i] == data[i-1]:
        i -= 1
        count += 1

    i = mid
    while data[i] == data[i+1]:
        i += 1
        count += 1
    return count + 1

if __name__ == "__main__":
    print(solution())