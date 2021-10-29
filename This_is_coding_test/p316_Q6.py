# 무지의 먹방 라이브
import heapq

def solution(food_times, k):
    answer = 0
    len_food = len(food_times)

    if sum(food_times) <= k:
        return -1

    q = []
    for food in range(len_food):
        heapq.heappush(q, (food_times[food], food+1))

    sum_time = 0
    pre_time = 0

    while sum_time + ((q[0][0] - pre_time) * len_food) <= k:
        food_time, idx = heapq.heappop(q)
        sum_time += (food_time - pre_time) * len_food
        len_food -= 1
        pre_time = food_time

    q.sort(key=lambda x:x[1])
    remind = k - sum_time
    food_len = len(q)
    return q[remind % food_len][1]

if __name__=="__main__":
    food_times = [3,1,2]
    k = 5
    print(solution(food_times, k))