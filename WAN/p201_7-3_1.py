if __name__ == '__main__':
    array = [19, 15, 10, 17]
    target = 6

    start = 0
    end = max(array)

    result = 0

    while(start <= end):
        total = 0
        mid = (start+end)//2

        for i in array:
            if i > mid:
                total += (i - mid)
            else:
                continue

        if total >= target:
            start = mid + 1
            result = mid
        else:
            end = mid - 1

    print(result)


