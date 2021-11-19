#include <iostream>
#include <algorithm>
#include <memory>

#pragma warning(disable:4996)

#define INF 2147483647
#define MAX_N 12
using namespace std;
int tcCnt;
int graph[MAX_N][MAX_N];
int memo[MAX_N][1 << MAX_N];
int num_customer;
int N;
int place_x[MAX_N];
int place_y[MAX_N];

int solve(int pos, int visited) {
	int& ret = memo[pos][visited];
	if (visited == ((1 << N) - 1 - 2)) {  // 모두 방문하고 집에만 안간경우
		if (ret != -1) return graph[pos][1];
		return ret = graph[pos][1];
	}
	ret = INF;
	for (int i = 2; i < N; ++i) {
		// 방문하지 않았으면
		if (!(visited & (1 << i))) {
			int tmp = graph[pos][i] + solve(i, visited | (1 << i));
			if (tmp < ret) ret = tmp;
		}
	}
	return ret;
}

void make_graph() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = abs(place_x[i] - place_x[j]) + abs(place_y[i] - place_y[j]);
		}
	}
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> num_customer;
		N = num_customer + 2;
		for (int i = 0; i < N; ++i) cin >> place_x[i] >> place_y[i];
		make_graph();
		memset(memo, 0x00, sizeof(memo));
		cout << "#" << t + 1 << ' ' << solve(0, 1) << endl;
	}
	return 0;
}