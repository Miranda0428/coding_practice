/* 에라토스테네스의 체 */
#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 1000001

int tcCnt;
int start, endv;
int arr[MAX_N];
int ps[MAX_N];
bool prime[MAX_N];

int solve() {
    int sqroot = sqrt(endv);
    for (int i = 2; i <= sqroot; i++) {
        for (int j = 2; j <= sqroot; j++) {
            prime[i * j] = true;
        }
    }

    for (int a = 0; a <= endv; a++) {
        arr[a] = a - 1;
    }

    for (int i = 2; i <= endv; i++) {
        if (!prime[i]) {
            for (int j = 1; i*j <= endv; j++) {
                arr[i * j] = (i - 1) * arr[j];
                //arr[i * j] = (i - 1) * (arr[i * j]/i);
            }
        }        
    }

    ps[0] = 0;
    for (int i = 1; i <= endv; i++)
        ps[i] = ps[i - 1] + arr[i];

    return ps[endv] - ps[start-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        memset(arr, 0x00, sizeof(int) * MAX_N);
        cin >> start >> endv;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}