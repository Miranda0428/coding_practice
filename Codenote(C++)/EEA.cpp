// CRT를 풀려면 EEA를 풀어야 한다.
// EEA로 풀어야할 식이 a ≡ 1 (mod b) 형태이므로 a의 역원을 구하는 것이 된다.
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

int CRT() {
    long M = 1;
    long answer = 0;

    for (int i = 0; i < N; ++i) M *= mod[i];

    for (int i = 0; i < N; ++i) {
        long tmp = M / mod[i];
        answer += arr[i] * tmp * computeInverse(tmp, mod[i]);
    }

    return answer %= M;
}
