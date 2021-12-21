#include <iostream>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 21

int tcCnt;
int N, L, R;
long long mat[MAX_N][MAX_N][MAX_N];

long long solve() {
    mat[1][1][1] = 1;
    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k)
                mat[i][j][k] = mat[i - 1][j][k - 1] + mat[i - 1][j - 1][k] + mat[i - 1][j][k] * (i - 2);

    return mat[N][L][R];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        memset(mat, 0x00, sizeof(int) * MAX_N * MAX_N * MAX_N);
        cin >> N >> L >> R;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}