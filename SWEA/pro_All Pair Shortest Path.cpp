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
                // �Ʒ�ó�� �������� ������ INF������ ���ؼ� ��Һ񱳸� �ϴ� ���� �߻�
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
            // ���۰� ������ ������ distance�� �ٸ� ��찡 �Է����� �־����� ��� ��������
            // �Ʒ�ó�� ���۰� ������ ������ distance�� �� ���� ��찡 �Է����� �־��� �ٸ� 
            // ����� �ڵ带 �߰����־����
            if (D[x][y] > z)              
                D[x][y] = z;
        }
      
        cout << "#" << t + 1 << ' ';
        solve();
        cout << "\n";
    }
    return 0;
}