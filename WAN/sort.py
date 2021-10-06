from copy import deepcopy
def selection_sort(array):
    mat = [0] * 10
    mat = deepcopy(array)

    for i in range(len(mat)):
        min_index = i
        for j in range(i+1, len(mat)):
            if mat[min_index] > mat[j]:
                mat[min_index], mat[j] = mat[j], mat[min_index]
    print(mat)
    return 0

def insertion_sort(array):
    mat = [0] * 10
    mat = deepcopy(array)

    for i in range(1, len(mat)):
        for j in range(i, 0, -1):
            if mat[j] < mat[j-1]:
                mat[j], mat[j-1] = mat[j-1], mat[j]
            else:
                break

    print(mat)
    return 0

def quick_sort(array):

    if len(array) <= 1:
        return array

    pivot = array[0]
    tail = array[1:]

    left = [x for x in tail if x <= pivot]
    print(left)
    right = [x for x in tail if x > pivot]
    print([pivot])
    print(right)
    print("=========")
    return quick_sort(left)+[pivot]+quick_sort(right)

def count_sort(array):
    mat = []
    tmp = [0] * 10

    for i in range(len(array)):
        tmp[array[i]] += 1

    for i in range(len(tmp)):
        for j in range(0, tmp[i]):
            mat.append(i)
    print(mat)
    return 0

if __name__=='__main__':

    array = [5,7,9,0,3,1,6,2,4,8]

    # selection_sort(array)
    # insertion_sort(array)
    quick_sort(array)
    # count_sort(array)