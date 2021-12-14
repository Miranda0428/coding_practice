#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

#define INF 2147483647
#define MAX_N 501

int tcCnt;
int N, M;
int D[MAX_N][MAX_N];

void solve() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                // 아래처럼 구현하지 않으면 INF값에다 더해서 대소비교를 하는 일이 발생
                if ((D[i][k] == INF) || (D[k][j] == INF))
                    continue;
                else if (D[i][j] == INF)
                    D[i][j] = D[i][k] + D[k][j];
                else
                    D[i][j] = min(D[i][j], (D[i][k] + D[k][j]));
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (D[i][j] == INF)
                D[i][j] = -1;
            cout << D[i][j] << ' ';
        }
    }
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        int x, y, z;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == j) D[i][j] = 0;
                else D[i][j] = INF;
            }
        }
        for (int i = 0; i < M; ++i) {
            cin >> x >> y >> z;
            // 시작과 끝점이 같은데 distance만 다른 경우가 입력으로 주어져서 계속 실패했음
            // 아래처럼 시작과 끝점이 같은데 distance가 더 작은 경우가 입력으로 주어진 다면 
            // 덮어쓰는 코드를 추가해주어야함
            if (D[x][y] > z)              
                D[x][y] = z;
        }
      
        cout << "#" << t + 1 << ' ';
        solve();
        cout << "\n";
    }
    return 0;
}