/*�̹����� largest�� �� �׽�Ʈ���̽����� 0���� �ʱ�ȭ���� �ʾ� ������ ���Դ�.
�� �׽�Ʈ���̽����� ���ŵǴ� ���� �ʱ�ȭ������.

���� LCS�� i,j index�� 1���� �����ؼ� length���� ����ϰ� �����Ƿ� 
LCS�� ����� length�� max���� 0~999�� �ƴ϶� 0~1000�� ����־�� �Ѵ�.(MAX_N = 1001)*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory.h>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 1001

int tcCnt;
int LCS[MAX_N][MAX_N];
string str_A, str_B;

int solve() {
    int len_A = str_A.size();
    int len_B = str_B.size();

    for (int i = 1; i <= len_A; ++i) {
        for (int j = 1; j <= len_B; ++j) {
            if (str_A[i-1] == str_B[j-1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else 
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
        }
    }  
    return LCS[len_A][len_B];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> str_A;
        cin >> str_B;
        memset(LCS, 0x00, sizeof(int) * MAX_N * MAX_N);
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}