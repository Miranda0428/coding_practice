/*����ǰ�� ������ 18���� ���� �Ҽ� {2,3,5,7,11,13,17} �� �ϳ��� Ȯ�� 
* 2���� ���(18C2 * (p)^2 * (1-p)^(18-2)) + 3���� Ȯ�� + ... + 17���� Ȯ��
* �ּ� �� �� �Ѹ��� ���� ����ǰ�� ������ �Ҽ��� Ȯ�� = 1 - (1-A�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��)(1-B�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��)
* ��, A�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��+B�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��-(A�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��)(B�� ���� ����ǰ�� ������ �Ҽ��� Ȯ��)*/
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