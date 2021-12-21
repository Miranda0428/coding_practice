/* 결과값인 cnt를 int 자료형으로 선언해서 fail
 Pole도 그렇고 결과값이 큰 값으로 예상될때는 long long으로 선언해야 한다.
 
 풀이 : mergesort를 사용해서 후배열의 원소(arr[j])가 선배열의 원소(arr[i])보다 큰 경우,
 즉, 선배열에서 후배열의 j 마다 arr[j] < arr[i]인 i의 갯수를 세어주면 된다.*/

#include <iostream>
#include <cstring>

//#pragma warning(disable:4996)
using namespace std;

#define MAX_N 100001

int tcCnt;
int len;
int arr[MAX_N];
long long cnt;

void mergesort(int arr[], int size) {
    if (size == 1) return;
    int mid = size / 2;
    mergesort(arr, mid);
    mergesort(arr + mid, size - mid);

    int* buf = new int[size];
    int i = 0; int j = mid; int k = 0;
    while ((i < mid) && (j < size)) {
        if (arr[i] > arr[j]) {
            cnt += mid - i;
            buf[k++] = arr[j++];
        }
        else
            buf[k++] = arr[i++];
        //buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }

    while (i < mid) buf[k++] = arr[i++];
    while (j < size) buf[k++] = arr[j++];

    for (int i = 0; i < size; ++i)
        arr[i] = buf[i];

    delete[] buf;
}

long long solve() {
    mergesort(arr, len);
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        memset(arr, 0x00, sizeof(int) * MAX_N);
        cin >> len;
        for (int i = 0; i < len; ++i)
            cin >> arr[i];
        cnt = 0;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}