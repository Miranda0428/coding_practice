# 카드 정렬하기
# 우선순위 큐 이용하기
n = int(input())
numbers = []
for _ in range(n):
    numbers.append(int(input()))

import heapq
def solution():
    pq = []
    sum = 0
    for i in numbers:
        heapq.heappush(pq, i)
    while len(pq) > 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        heapq.heappush(pq, a+b)
        sum += a+b
    return sum

print(solution())