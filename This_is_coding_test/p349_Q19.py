# 연산자 끼워 넣기 - bruteforce
import time
from itertools import permutations
from collections import deque
def solution(n, nums, oper):
    oper_list = []
    for _ in range(oper[0]):
        oper_list.append('+')
    for _ in range(oper[1]):
        oper_list.append('-')
    for _ in range(oper[2]):
        oper_list.append('*')
    for _ in range(oper[3]):
        oper_list.append('/')

    # list(permutations(oper_list))로 하면 리스트 원소중에 중복되는 경우가 생긴다.
    # set(permutations(oper_list))로 해주어야 중복되는 경우를 제외하여 시간초과를 피할수 있다.
    # dfs로 풀면 더 빨리 풀 수 있다.
    opers = set(permutations(oper_list))

    max_total = -1e9
    min_total = 1e9

    for op in opers:
        num = deque(nums)
        total = num.popleft()
        for i in range(n-1):
            if op[i] == '+':
                total += num.popleft()
            if op[i] == '-':
                total -= num.popleft()
            if op[i] == '*':
                total *= num.popleft()
            if op[i] == '/':
                if total < 0:
                    total = -1 * total
                    total //= num.popleft()
                    total = -1 * total
                else:
                    total //= num.popleft()
        max_total = max(max_total, total)
        min_total = min(min_total, total)

    print(max_total)
    print(min_total)

    # answer = []
    #
    # for op in opers:
    #     num = deque(nums)
    #     total = num.popleft()
    #     for i in range(n-1):
    #         if op[i] == '+':
    #             total += num.popleft()
    #         if op[i] == '-':
    #             total -= num.popleft()
    #         if op[i] == '*':
    #             total *= num.popleft()
    #         if op[i] == '/':
    #             if total < 0:
    #                 total = -1 * total
    #                 total //= num.popleft()
    #                 total = -1 * total
    #             else:
    #                 total //= num.popleft()
    #     answer.append(total)
    #
    # print(max(answer))
    # print(min(answer))

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    oper = list(map(int, input().split()))

    start = time.time_ns()
    solution(n, nums, oper)
    end = time.time_ns()

    print("TIME :", end-start)