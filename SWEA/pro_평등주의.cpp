/*정리 필요*/
#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 100000
#define MAX_K 1000000000

int tcCnt;
int N, K;
int arr[MAX_N];
int tmp[MAX_N];
int op_cnt;

int solve(int left, int right) {
    int mid = 0; int gap = 0; int answer = 0;
    while (left < right) {
        mid = (left + right) / 2;
        for (int i = 0; i < N; ++i)
            tmp[i] = arr[i];
        op_cnt = 0;
        for (int i = 0; i < N - 1; ++i) {
            gap = tmp[i+1] - tmp[i];
            if (gap > mid) {
                tmp[i+1] -= (gap - mid);
                op_cnt += (gap - mid);
                if (op_cnt > K)
                    i = N;
            }
        }

        for (int i = N-1; i > 0; --i) {
            gap = tmp[i-1] - tmp[i];
            if (gap > mid) {
                tmp[i-1] -= (gap - mid);
                op_cnt += (gap - mid);
                if (op_cnt > K)
                    i = N;
            }
        }
        
        if (op_cnt <= K)
            answer = right = mid;
        else 
            answer = left = mid + 1;
    }
    return answer;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        memset(arr, 0x00, sizeof(int) * MAX_N);
        memset(tmp, 0x00, sizeof(int) * MAX_N);
        cin >> N >> K;
        for (int i = 0; i < N; ++i)
            cin >> arr[i];
        op_cnt = 0;
        cout << "#" << t + 1 << ' ' << solve(0, MAX_K) << endl;
    }
    return 0;
}