#include <iostream>
#include <algorithm>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int tcCnt;
int dalant;
int bundle;

long long solve() {

    int quotient = dalant / bundle;
    int remainder = dalant % bundle;

    return pow(quotient, (bundle - remainder)) * pow((quotient + 1), remainder);
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;

    for (int t = 0; t < tcCnt; ++t) {
        cin >> dalant >> bundle;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}