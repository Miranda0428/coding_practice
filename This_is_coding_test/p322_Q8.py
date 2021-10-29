# 문자열 재정렬
def solution():
    text = []
    sum = 0
    data = list(input())
    n = len(data)

    for i in data:
        if ord(i) > 0x40:   # '0' = 0x30, 'A' = 0x41, 'a' = 0x61
            text.append(i)
        else:
            sum += int(i)
    text.sort()             # 문자열 sort 가능!
    text.append(sum)

    for i in text:
        print(i, end='')


if __name__ == '__main__':
    solution()