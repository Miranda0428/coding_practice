/*1->2�� INF-3�� ��쿡 ���ؼ� error�� �ְ�
������ �������� �ߵ��ư��µ�
�����ϸ� 0�� �¾Ҵٰ� �����̶�� ���´�.
���� �� �ٸ��� ���� ���ͳݻ��� java�ڵ�� �н��� �ϴµ� ������ ���������� �𸣰ڴ�.

INF ���� ���Ҷ��� �����ؾ� �� ���� ����ġ�� ���Ҷ� INF�� ���ؼ� ���������� ���ϴ� ��찡 �����.
�׷��� ���� �̷� ������ ���ϱ� ���� D ��Ʈ���� �ʱ�ȭ�� -1�� ����Ͽ���.

memset�� ����Ʈ���� hex������ �ʱ�ȭ�ϱ� ������ 0 �Ǵ� -1�� �ƴϸ� ������ ���� ������ ��� �� ������ �����ؾ��Ѵ�.*/
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