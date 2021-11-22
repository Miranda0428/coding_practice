/* dijkstra�� Ǭ��.*/
/* dfs�� Ǯ �� ���� �� ����.*/
/* bfs�ε� Ǯ �� �ִ�.*/
/* ������ϰ� ���� �ð��� ����. �ڵ� ¥�� ������ �ִ�. �̰� �ܿ��� �ð��� �����ؾ� �Ѵ�.
* ���� visited[x][y] = 1 �س��� solve() ȣ�� �� �ٽ� visited[x][y] = 0 ���� �����Ѵٴ���
* ����ġ��, �޸������̼� �� ���� ������ ����� ������ �ܿ��� �Ѵ�.*/
// ����Ž��, �׸���, dfs-bfs ������ 50���� Ǯ��� ���� �̷� �� �ΰ�����.

#include <iostream>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)
#define INF 2147483647
#define MAX_N 100

int tcCnt;
int N;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

// �����¿� ������ ��� �ϴ��ĵ� �ð��ʰ� �Ǵ� �����÷ο츦 ����Ų��.
// �Ʒ��� ���� �������� ������ �����־�� ���� ����ȴ�.(������ ���� �ٸ�����)
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = {  0, 0,-1, 1 };

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {  0, 1, 0,-1};

int ret;

int dfs_solve(int x, int y, int sum) {

	if ((x == (N - 1)) & (y == (N - 1))) {
		if (sum < ret) {
			ret = sum;
			return ret;
		}
	}

	if ((ret > 0) & (sum >= ret)) return ret;

	if (dist[x][y] > sum) dist[x][y] = sum;
	else return ret;

	for (int i = 0; i < 4; ++i) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if ((next_x < 0) | (next_y < 0) | (next_x >= N) | (next_y >= N))
			continue;
		else if (visited[next_x][next_y]) continue;
		else {
			visited[next_x][next_y] = 1;
			dfs_solve(next_x, next_y, sum + map[next_x][next_y]);
			visited[next_x][next_y] = 0;
		}		
	}
	return ret;
}

//int dijkstra_solve(int x, int y) {
//
//	
//}

int main() {
	//freopen("test_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	int row;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N;++j) {
				// ����� �Է°��� �־����°��� scanf("%d",&data)
				// �پ �Է°��� �־����� ����
				scanf("%1d", &map[i][j]);
				visited[i][j] = 0;
				dist[i][j] = INF;
			}
		}
		visited[0][0] = 1;
		ret = INF;
		//cout << "#" << t + 1 << ' ' << dijkstra_solve(0, 0, 0) << endl;
		cout << "#" << t + 1 << ' ' << dfs_solve(0, 0, 0) << endl;
	}
	return 0;
}