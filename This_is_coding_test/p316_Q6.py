
def solution(food_times, k):
    answer = 0
    len_f = len(food_times)

    ind = 0
    time = 0

    while time < k and sum(food_times)!=0:
        if ind >= len_f:
            ind = ind % len_f

        if food_times[ind] != 0:
            food_times[ind] -= 1
            time += 1
            ind += 1
        else:
            ind += 1
            continue

    if sum(food_times)==0:
        return -1

    if ind >= len_f:
        ind = ind % len_f

    while food_times[ind] == 0:
        ind += 1
        if ind >= len_f:
            ind = ind % len_f
        else:
            continue

    return (ind + 1) % len_f

if __name__=="__main__":
    food_times = [0,0,0,0,0,0,0]
    k = 5
    print(solution(food_times, k))