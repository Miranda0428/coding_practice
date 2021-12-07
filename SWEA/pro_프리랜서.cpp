/* opt�� day �������� �ߴ��� run time over�� ���� task �������� �ߴ�.
opt�� p�� �׽�Ʈ ���̽� ���� 0���� �ʱ�ȭ �� �� �����ؾ� �Ѵ�.
pro ���� ���ʹ� �׽�Ʈ���̽��� 1���� �־����� ���� �����ϸ� 10���� �׽�Ʈ���̽��� �˻��Ѵ�.
���� �������̽��� ����� �� �ֵ��� �Ĳ��� �����ϰ� ���� �ӵ��� �Ű��� �Ѵ�.*/

#include <iostream>
#include <algorithm>
#include <memory.h>

#pragma warning(disable:4996)
#define MAX_N 10001

using namespace std;
int tcCnt;
int task, day;
int start, end_day;
int money;

struct WORK {
    int start;
    int end_day;
    int money;
}work[MAX_N];

int opt[MAX_N];
int p[MAX_N];

bool compare(WORK& work1, WORK& work2) {
    if (work1.end_day < work2.end_day)
        return true;
    else
        return false;
}

int solve() {
    sort(work, work + task, compare);
    memset(p, 0x00, sizeof(int) * 10000);
    for (int i = 2; i <= task; ++i) {
        for (int j = 1; j < i; ++j) {
            if (work[j].end_day < work[i].start)
                p[i] = j;
        }
    }

    memset(opt, 0x00, sizeof(int) * 10000);
    for (int j = 1; j <= task; ++j) 
        opt[j] = max(opt[j - 1], work[j].money + opt[p[j]]);
    return opt[task];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> task >> day;
        for (int i = 1; i <= task; ++i)
            cin >> work[i].start >> work[i].end_day >> work[i].money;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}