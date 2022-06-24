#include <iostream>

#pragma warning(disable:4996)
using namespace std;

#define MAX_W 200000

int tcCnt;
int N, K;
int W[MAX_W+1];
int S[MAX_W+1];

bool IsPossible(int middle) {
    int cnt = 0;
    int data = 0;

    for (int i = 0; i < N; ++i) {
        if (W[i] <= middle) cnt++;
        else cnt = 0;

        if (cnt == S[data]) {
            data++;
            cnt = 0;
        }

        if (data == K)
            return true;
    }
    return false;
}

int solve(int start, int end) {

    while (start < end) {
        int mid = (start + end) / 2;

        if (IsPossible(mid))
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> N;
        cin >> K;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &W[i]);
        }
        for (int i = 0; i < K; ++i) {
            scanf("%d", &S[i]);
        }
        cout << "#" << t + 1 << ' ';
        cout << solve(1, MAX_W);
        cout << endl;
    }
    return 0;
}