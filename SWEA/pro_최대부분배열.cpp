/*정리 필요*/
#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 200001

int tcCnt;
int N;
int arr[MAX_N];
int ps[MAX_N];
int min_v[MAX_N];

int solve1() {
    int answer, max_v;
    memset(ps, 0x00, sizeof(int) * (N+1));
    memset(min_v, 0x00, sizeof(int) * (N + 1));
    
    for (int i = 1; i <= N; ++i) {
        ps[i] = ps[i-1] + arr[i];
        min_v[i] = min(min_v[i-1], ps[i]);
    }

    max_v = ps[1];
    for (int j = 2; j <= N; ++j) {
        int tmp = ps[j] - min_v[j-1];
        if (max_v < tmp)
            max_v = tmp;
    }
        
    return max_v;
}

// 제한시간 초과!!
int solve2()
{
    int answer;
    int max_v = arr[0];

    memset(ps, 0x00, sizeof(int) * (N+1));
    ps[0] = arr[0];
    for (int i = 1; i < N; ++i) {
        ps[i] = ps[i - 1] + arr[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            int tmp = ps[i] - ps[j];
            if (max_v < tmp) max_v = tmp;
        }
    }

    return max_v;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; t++) {
        cin >> N;
        memset(arr, 0x00, sizeof(int) * N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &arr[i]);
        cout << "#" << t + 1 << ' ' << solve1() << endl;
    }
    return 0;
}
