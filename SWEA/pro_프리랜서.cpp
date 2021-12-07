/* opt를 day 기준으로 했더니 run time over가 나서 task 기준으로 했다.
opt와 p를 테스트 케이스 마다 0으로 초기화 한 후 시작해야 한다.
pro 문제 부터는 테스트케이스가 1개만 주어지고 실제 제출하면 10개의 테스트케이스로 검사한다.
따라서 히든케이스도 통과할 수 있도록 꼼꼼히 봐야하고 연산 속도도 신경써야 한다.*/

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