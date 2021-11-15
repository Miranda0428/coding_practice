//https://blog.fakecoding.com/archives/think-recursion-algorithm/

#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;
int tcCnt;
int comp_x, comp_y;
int home_x, home_y;
int num_customer;
int customer_x[10];
int customer_y[10];
int visited[10];

int distance = 0;
int ret = 1e9;

int solve(int x, int y, int cnt, int distance, int* visited) {

	if (cnt == 0) {
		distance += abs(x - home_x) + abs(y - home_y);
		if (ret > distance)
			ret = distance;
	}

	for (int i = 0; i < num_customer; ++i) {
		if (visited[i] == -1) {
			distance += abs(x - customer_x[i]) + abs(y - customer_y[i]);
			visited[i] = 1;
			solve(customer_x[i], customer_y[i], cnt - 1, distance, visited);
			visited[i];
			}
	}		

	return ret;
}


int main(int argc, char** argv) {
	freopen("test_input.txt", "r", stdin);
	cin >> tcCnt;
	cin >> num_customer;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> comp_x >> comp_y;
		cin >> home_x >> home_y;

		for (int i = 0; i < num_customer; ++i) {
			cin >> customer_x[i] >> customer_y[i];
			visited[i] = -1;
		}
		cout << "#" << t + 1 << ' ' << solve(comp_x, comp_y, num_customer, 0, visited) << endl;
	}
	return 0;
}
