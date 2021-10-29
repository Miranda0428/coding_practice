# 국영수
def solution():

    n = int(input())
    data = [0] * n

    for i in range(n):
        data[i] = tuple(input().split())

    data.sort(key=lambda x: (-int(x[1]),int(x[2]),-int(x[3]),x[0]))  # sort에서의 lambda 사용 외우기!!
                                                                     # map(int, input().split())은 띄어쓰기로 구분되는 input에 대해서 모두 int 함수를 적용한다는 뜻

    for i in range(n):
        print(data[i][0], end=' ')

if __name__=="__main__":
    solution()