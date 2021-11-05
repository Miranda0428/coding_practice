# 안테나
n = int(input())
house = list(map(int, input().split()))
min_house = 0

# 이렇게 정석으로 풀면 시간초과됨

# def solution():
#     min_total = 1e9
#     for h in house:
#         total = 0
#         for i in house:
#             total += abs(i - h)
#         if min_total > total:
#             min_total = total
#             min_home = h
#         elif min_total == total:
#             if min_home > h:
#                 min_home = h
#         else:
#             continue
#
#     return min_home

def solution():
    house.sort()
    return house[(n-1)//2]

print(solution())