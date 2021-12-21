/* ������� cnt�� int �ڷ������� �����ؼ� fail
 Pole�� �׷��� ������� ū ������ ����ɶ��� long long���� �����ؾ� �Ѵ�.
 
 Ǯ�� : mergesort�� ����ؼ� �Ĺ迭�� ����(arr[j])�� ���迭�� ����(arr[i])���� ū ���,
 ��, ���迭���� �Ĺ迭�� j ���� arr[j] < arr[i]�� i�� ������ �����ָ� �ȴ�.*/

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