/* 같은 코드인데 JAVA 코드는 Pass이고 C++ 코드는 시간초과란다. */
#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 1000001

int tcCnt;
int start, endv;
int arr[MAX_N];
int ps[MAX_N];
bool comp[MAX_N];

int solve() {
    comp[1] = true;
    for (int i = 2; i*i <= endv; i++) {
        if (comp[i] == false) {
            for (int j = 2; i * j <= endv; j++) {
                comp[i * j] = true;
            }
        }        
    }

    for (int i = 1; i <= endv; i++)
        arr[i] = i;

    for (int i = 2; i <= endv; i++) {
        // 소수이면
        if (comp[i]==false) {
            // 배수들에 대한 처리
            for (int j = 1; i * j <= endv; j++) {
                arr[i * j] = (i - 1) * (arr[i * j] / i);
            }
        }
    }

    ps[0] = 0; ps[1] = 1;
    for (int i = 2; i <= endv; i++)
        ps[i] = ps[i - 1] + arr[i];

    return ps[endv] - ps[start-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        //memset(arr, 0x00, sizeof(int) * MAX_N);
        cin >> start >> endv;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}