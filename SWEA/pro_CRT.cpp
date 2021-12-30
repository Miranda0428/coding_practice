#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 10

int tcCnt;
int N;
int arr[MAX_N];
int mod[MAX_N];

long computeInverse(long a, int b) {
    long m = b, t, q;
    long x = 0, y = 1;

    if (b == 1) return 0;

    // 유클리드 알고리즘 적용
    while (a > 1) {
        q = a / b;

        t = b;
        b = (int)(a % b);
        a = t;

        t = x;
        x = y - q * x;
        y = t;
    }

    // 음수이면 양수로 만들기
    if (y < 0) y += m;

    return y;
}

// 수정이 안됨...식을 이해하지 못함. 위의 computeinverse를 활용토록.
long EEA(long m, int n) {
    long r=0, r1 = m, r2 = n;
    long s=0, s1=1, s2=0;
    long q, tmp_s;

    if (n == 1) return 0;

    if (r1 < r2) {
        int tmp = r2;
        r2 = (int)(r1 % r2);
        r1 = tmp;
    }

    while (r2 > 0){
        tmp_s = s;
        q = r1 / r2;
        
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        
        s = s1 - q * s2;
        s1 = s2;
        s2 = s;
    }

    if (tmp_s < 0) 
        tmp_s += n;

    return tmp_s;
}


int solve() {
    long M = 1;
    long answer = 0;

    for (int i = 0; i < N; ++i) M *= mod[i];

    for (int i = 0; i < N; ++i) {
        long tmp = M / mod[i];
        answer += arr[i] * tmp * computeInverse(tmp, mod[i]);
    }

    return answer %= M;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; t++) {
        cin >> N;
        memset(arr, 0x00, sizeof(int) * N);
        for (int i = 0; i < N; ++i)
            cin >> arr[i] >> mod[i];
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}