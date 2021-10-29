# 치킨 배달
from itertools import combinations
def solution(n, m, town):
    INF = 1e9
    house = []
    chicken_store = []
    for x in range(n):
        for y in range(n):
            if town[x][y] == 1:
                house.append((x+1, y+1))
            elif town[x][y] == 2:
                chicken_store.append((x+1, y+1))
            else:
                continue

    comb_ret = list(combinations(chicken_store, m))

    min_city_distance = INF
    for chicken_pairs in comb_ret:
        city_distance = 0
        for h in house:
            hx, hy = h
            min_distance = INF
            for pair in chicken_pairs:
                cx, cy = pair
                distance = abs(cx - hx) + abs(cy - hy)
                min_distance = min(distance, min_distance)
                # print(min_distance)
            city_distance += min_distance
            # print(city_distance)
        min_city_distance = min(city_distance, min_city_distance)

    return min_city_distance

if __name__ == "__main__":
    n, m = map(int, input().split())
    town = []
    for _ in range(n):
        town.append(list(map(int, input().split())))
    print(solution(n, m, town))