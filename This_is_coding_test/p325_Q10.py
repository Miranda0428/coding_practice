# 자물쇠와 열쇠
def rotation(key, key_len):
    rot_key = [[0 for _ in range(key_len)] for _ in range(key_len)]
    for i in range(key_len):
        for j in range(key_len):
            rot_key[j][key_len-1-i] = key[i][j]
    return rot_key

# [1,1,1,1,1,1,1] 배열을 만들어서 행렬의 1 row씩 비교하게하니 런타임 오류 발생
def check(large_mat, lock_len, key_len):
    iter_end = key_len + lock_len - 1
    for row in range(key_len-1, iter_end):
        for col in range(key_len-1, iter_end):
            if large_mat[row][col] != 1:
                return False
    return True

def solution(key, lock):
    key_len = len(key)     # m
    lock_len = len(lock)   # n
    large_size = 2 * key_len + lock_len - 2
    large_mat = [[1 for _ in range(large_size)] for _ in range(large_size)]
    rot_key = [[[0 for _ in range(key_len)] for _ in range(key_len)] for _ in range(4)]

    # rot_key에 키를 사방으로 회전시킨 결과값 저장
    rot_key[0] = key
    for i in range(1, 4):
        rot_key[i] = rotation(rot_key[i-1], key_len)

    # large_mat에 lock 배치
    for i in range(lock_len):
        for j in range(lock_len):
            large_mat[key_len - 1 + i][key_len - 1 + j] = lock[i][j]

    iter_size = lock_len + key_len - 1
    for i in range(iter_size):
        for j in range(iter_size):
            for k in range(4):
                for row in range(key_len):
                    for col in range(key_len):
                        large_mat[i + row][j + col] += rot_key[k][row][col]
                # lock 위치에 있는 값을 tmp에 복사 <- 런타임 오류 발생!
                if check(large_mat, lock_len, key_len):
                    return True
                for row in range(key_len):
                    for col in range(key_len):
                        large_mat[i + row][j + col] -= rot_key[k][row][col]
    return False

if __name__ == '__main__':
    key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
    lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    # key = [[1, 1, 1], [1, 1, 1], [0, 0, 0]]
    # lock = [[1, 0, 0], [1, 0, 0], [1, 0, 0]]
    print(solution(key, lock))