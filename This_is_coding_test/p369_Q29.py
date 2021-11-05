# 공유기 설치
# 파라메트릭 서치 문제 - 재귀함수보다는 반복문으로 푼다.

n, c = map(int, input().split())
house = []
for _ in range(n):
    house.append(int(input()))

def solution():
    distance = 0
    house.sort()
    start = 1
    end = house[n-1] - house[0]

    while start <= end:
        cnt = 1
        mid = (start + end) // 2
        pre_house = house[0]
        for i in range(1, n):
            if (house[i] - pre_house) >= mid:
                cnt += 1
                pre_house = house[i]
        if cnt >= c:
            start = mid + 1
            distance = max(distance, mid)
        else:
            end = mid - 1

    return distance

print(solution())