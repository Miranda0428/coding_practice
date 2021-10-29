# 모험가 길드
# general rule
# 1. 공포지수를 오름차순으로 sort한다.
# 2. 인덱스 0에서 부터 그룹을 지어나간다.
# 3. 인덱스 1에서 부터 그룹을 지어나간다.
# 4. 인덱스 n-1까지 가서 그룹을 지어보고 그룹 갯수의 최대값을 출력한다.

import time

# n = input()
# data = list(map(int, input().split()))

n = 9
data = [1,1,1,3,3,3,3,4,5]

def test():
    max_group = 0
    group = 0
    data.sort(reverse=True)

    for ind in range(n):
        group = 0
        while True:
            if data[ind] > (n - ind):
                continue
            next_ind = data[ind]
            group += 1
            ind = ind + next_ind
            if ind >= n:
                max_group = max(max_group, group)
                break
    print(max_group)

if __name__=="__main__":
    start_time = time.time()
    test()
    end_time = time.time()
    print(end_time-start_time)