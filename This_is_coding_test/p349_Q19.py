# 연산자 끼워 넣기
# 3번째 TC 최대값이 틀렸음
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

    opers = list(permutations(oper_list, n-1))

    max_total = 0
    min_total = 1e9

    for op in opers:
        num = (deque(nums))
        total = num.popleft()
        for i in range(n-1):
            if op[i] == '+':
                total += num.popleft()
            if op[i] == '-':
                total -= num.popleft()
            if op[i] == '*':
                total *= num.popleft()
            if op[i] == '/':
                total //= num.popleft()
        max_total = max(max_total, total)
        min_total = min(min_total, total)

    print(max_total)
    print(min_total)

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    oper = list(map(int, input().split()))

    solution(n, nums, oper)