# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import time

def test():

    #n, m, k = map(int, input().split())
    #data = list(map(int, input().split()))
    n, m, k = 5, 8, 3
    data = [2, 4, 5, 4, 6]
    data.sort()

    biggest = data[n - 1]
    second_one = data[n - 2]

    q = m // k
    r = m % (k+1)
    mul = q * k

    result = 0
    result = mul * biggest
    result += q * second_one

    if r==0:
        return result
    else:
        result += r * biggest
        return result

# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    start_time = time.time()
    print(test())
    end_time = time.time()

    print("time : ", end_time - start_time)
