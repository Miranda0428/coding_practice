/*완제품의 갯수가 18보다 작은 소수 {2,3,5,7,11,13,17} 중 하나일 확률 
* 2개일 경우(18C2 * (p)^2 * (1-p)^(18-2)) + 3개일 확률 + ... + 17개일 확률
* 최소 둘 중 한명이 만든 완제품의 갯수가 소수일 확률 = 1 - (1-A가 만든 완제품의 갯수가 소수일 확률)(1-B가 만든 완제품의 갯수가 소수일 확률)
* 즉, A가 만든 완제품의 갯수가 소수일 확률+B가 만든 완제품의 갯수가 소수일 확률-(A가 만든 완제품의 갯수가 소수일 확률)(B가 만든 완제품의 갯수가 소수일 확률)*/
#include <iostream>
#include <algorithm>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int tcCnt;
double A_prob;
double B_prob;

double solve() {

    int prime[7] = { 2,3,5,7,11,13,17 };
    double A_prob_sum = 0, B_prob_sum = 0;

    for (int i = 0; i < 7; ++i) {
        int comb = 1;
        for (int j = 0; j < prime[i]; ++j) {
            comb *= (18 - j);
            comb /= (j + 1);
        }
        A_prob_sum += comb * pow(A_prob, prime[i]) * pow((1 - A_prob), (18 - prime[i]));
        B_prob_sum += comb * pow(B_prob, prime[i]) * pow((1 - B_prob), (18 - prime[i]));
    }
    return A_prob_sum + B_prob_sum - A_prob_sum*B_prob_sum;
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;

    for (int t = 0; t < tcCnt; ++t) {
        cin >> A_prob >> B_prob;
        A_prob /= 100;
        B_prob /= 100;
        cout << "#" << t + 1 << ' ';
        printf("%6f" , solve());
        cout << "\n";
    }   
    return 0;
}