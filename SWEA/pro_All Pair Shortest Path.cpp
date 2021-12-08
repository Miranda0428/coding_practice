/*1->2가 INF-3인 경우에 대해서 error가 있고
나머지 값에서는 잘돌아가는데
제출하면 0개 맞았다고 오답이라고 나온다.
나랑 별 다를게 없는 인터넷상의 java코드는 패스를 하는데 원인이 무엇인지를 모르겠다.

INF 값을 정할때도 주의해야 할 것이 가중치를 더할때 INF에 더해서 음수값으로 변하는 경우가 생긴다.
그래서 나는 이런 오류를 피하기 위해 D 매트릭스 초기화시 -1을 사용하였다.

memset도 바이트별로 hex값으로 초기화하기 때문에 0 또는 -1이 아니면 생각지 못한 값으로 덮어쓸 수 있으니 유의해야한다.*/
#include <iostream>
#include <algorithm>
#include <memory.h>

#pragma warning(disable:4996)

using namespace std;

//#define INF 1000000
//#define INF 2147483647
#define MAX_N 501

int tcCnt;
int N, M;
int D[MAX_N][MAX_N];

void solve() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if ((D[i][k] == -1) || (D[k][j] == -1))
                    continue;
                else if (D[i][j] == -1)
                    D[i][j] = D[i][k] + D[k][j];
                else
                    D[i][j] = min(D[i][j], (D[i][k] + D[k][j]));
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << D[i][j] << ' ';
        }
    }
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        //memset(D, INF, sizeof(int) * MAX_N * MAX_N);
        int x, y, z;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == j) D[i][j] = 0;
                else D[i][j] = -1;
            }
        }
        for (int i = 0; i < M; ++i) {
            cin >> x >> y >> z;
            D[x][y] = z;
        }
      
        cout << "#" << t + 1 << ' ';
        solve();
        cout << "\n";
    }
    return 0;
}