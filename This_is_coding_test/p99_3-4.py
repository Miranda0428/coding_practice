import time

def test():

    #n, m, k = map(int, input().split())
    #data = list(map(int, input().split()))
    n, k = 25, 3

    tmp_n = n
    count = 0
    ans = 0

    while ans!=1:
        if(tmp_n < k):
            count += (tmp_n - 1)
            return count
        else:
            r = tmp_n % k
            if r!=0:
                count += r
                tmp_n -= r
            tmp_n = tmp_n // k
            count += 1
            ans = tmp_n
    return count

if __name__ == '__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)3-4
