# 기둥과 보 설치
def check(answer):
    for x, y, stuff in answer:
        if stuff == 0:
            if y == 0 or [x-1, y, 1] in answer or [x, y, 1] in answer or [x, y-1, 0] in answer:
                continue
            else:
                return False
        else:
            if [x, y-1, 0] in answer or [x+1, y-1, 0] in answer or [x-1, y, 1] in answer or [x+1, y, 1] in answer:
                continue
            else:
                return False
    return True


def solution(n, build_frame):
    answer = []
    for frame in build_frame:
        x, y, stuff, operate = frame
        if operate == 1:        # 설치
            answer.append([x, y, stuff])
            if check(answer): continue
            else: answer.remove([x, y, stuff])
        else:                   # 삭제
            answer.remove([x, y, stuff])
            if check(answer): continue
            else: answer.append([x, y, stuff])

    # answer.sort()
    return sorted(answer)

if __name__ == "__main__":
    # n = int(input())
    # build_frame = [[2 for _ in range(4)]]
    n = 5
    build_frame = [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]
    print(solution(n, build_frame))