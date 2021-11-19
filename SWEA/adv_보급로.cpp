#include <iostream>

using namespace std;

#define MAX_N 100
#define INF 1e9;
int src_x, src_y;
int dst_x, dst_y;
int time[MAX_N][MAX_N];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solve(int x, int y, int sum) {

	if (x == dst_x & y == dst_y) return sum;

	int ret = INF;

	for (int i = 0; i < 4; ++i) {
		int tmp = solve(x + dx[i], y + dy[i], sum + time[x + dx[i]][y + dy[i]]);
		if (tmp < ret) ret = tmp;
	}
	return ret;
}




int main() {

	return 0;
}