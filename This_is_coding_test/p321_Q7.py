def solution():
    num = list(input())            # 파이썬은 모든 입력을 str로 받는다. 리스트로 만들고 싶으면 list()를 써야한다.
    len_n = len(num)

    for i in range(len_n):
        num[i] = int(num[i])

    suml = sum(num[0:(len_n//2)])    # len_n/2이 아니라 len_n//2으로 해야한다. int/int 결과는 float이기 때문이다.
    sumr = sum(num[(len_n//2):])

    if suml==sumr:
        print("LUCKY")
    else:
        print("READY")


if __name__ == '__main__':
    solution()