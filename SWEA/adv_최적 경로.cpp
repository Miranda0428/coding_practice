#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

#define INF 2147483647
using namespace std;
int tcCnt;
int comp_x, comp_y;
int home_x, home_y;
int num_customer;
int customer_x[11];
int customer_y[11];
//int ret = INF;     // 2^31 - 1 (signed int로 만들수 있는 최대값)

int solve(int x, int y, int visited) {
	if (visited == ((1 << (num_customer + 1)) - 1)) {
		return abs(x - home_x) + abs(y - home_y);
	}
	int ret = INF;
	for (int i = 1; i < (num_customer + 1); ++i) {
		// 방문하지 않았으면
		if (!(visited & (1 << i))) {
			int tmp = abs(x - customer_x[i]) + abs(y - customer_y[i]);
			tmp += solve(customer_x[i], customer_y[i], visited | (1 << i));
			/*cout << tmp << ' ';
			cout << ret << endl;*/
			if (tmp < ret) ret = tmp;
		}
	}
	return ret;
}


int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> num_customer;
		cin >> comp_x >> comp_y;
		cin >> home_x >> home_y;
		for (int i = 1; i < (num_customer + 1); ++i) cin >> customer_x[i] >> customer_y[i];

		cout << "#" << t + 1 << ' ' << solve(comp_x, comp_y, 1) << endl;
	}
	return 0;
}