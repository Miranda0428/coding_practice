/* dijkstra로 푼다.*/
/* dfs로 풀 수 있을 것 같다.*/
/* bfs로도 풀 수 있다.*/
/* 디버깅하고 있을 시간이 없다. 코드 짜는 유형이 있다. 이걸 외워서 시간을 단축해야 한다.
* 가령 visited[x][y] = 1 해놓고 solve() 호출 후 다시 visited[x][y] = 0 으로 원복한다던지
* 가지치기, 메모이제이션 등 많이 나오는 경우의 유형을 외워야 한다.*/
// 완전탐색, 그리디, dfs-bfs 문제는 50개씩 풀라는 말이 이런 뜻 인가보다.

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

// 상하좌우 순서를 어떻게 하느냐도 시간초과 또는 오버플로우를 일으킨다.
// 아래와 같이 상후하좌 순서를 정해주어야 빨리 연산된다.(문제에 따라 다를수도)
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
				// 띄워서 입력값이 주어지는경우는 scanf("%d",&data)
				// 붙어서 입력값이 주어지는 경우는
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