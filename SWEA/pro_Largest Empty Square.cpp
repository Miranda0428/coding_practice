/*�̹����� largest�� �� �׽�Ʈ���̽����� 0���� �ʱ�ȭ���� �ʾ� ������ ���Դ�.
�� �׽�Ʈ���̽����� ���ŵǴ� ���� �ʱ�ȭ������.*/

#include <stdio.h>
#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
#define MAX_N 1000

using namespace std;
int tcCnt;
int N;
int mat[MAX_N][MAX_N];
int largest;

int solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mat[i][j] == 1)
                mat[i][j] = 0;
            else if ((i == 0) || (j == 0))
                mat[i][j] = 1;
            else{
                int tmp = min(mat[i - 1][j - 1], mat[i][j - 1]);
                mat[i][j] = min(tmp, mat[i - 1][j]) + 1;
            }

            if (largest < mat[i][j])
                largest = mat[i][j];
        }
    }
    return largest;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                scanf("%1d", &mat[i][j]);
        largest = 0;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}