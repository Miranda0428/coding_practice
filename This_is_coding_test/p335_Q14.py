# 외벽 점검
from itertools import permutations
def solution(n, weak, dist):
    dist_len = len(dist)
    weak_len = len(weak)

    # 원형을 한줄로 늘이기
    for i in range(weak_len):
        weak.append(weak[i] + n)

    dist_list = list(permutations(dist))
    min_cnt = dist_len + 1

    for d in dist_list:
        for w in range(weak_len):
            cnt = 0
            position = weak[w] + d[cnt]
            for index in range(w, w + weak_len):
                if position < weak[index]:
                    cnt += 1
                    # cnt는 실제 친구수 보다 1 작은데 if cnt > dist_len:로 구현해서 오류를 찾지 못함.
                    if cnt + 1 > dist_len:
                        break
                    position = weak[index] + d[cnt]
            min_cnt = min(cnt, min_cnt)

    friend = min_cnt + 1
    if friend > dist_len:
        return -1

    return friend

if __name__ == "__main__":
    n = 12
    weak = [1, 3, 4, 9, 10]
    dist = [3, 5, 7]
    # weak = [1, 5, 6, 10]
    # dist = [1, 2, 3, 4]

    print(solution(n, weak, dist))