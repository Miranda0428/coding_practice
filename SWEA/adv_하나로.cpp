#include <iostream>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)
#define INF 2147483647
#define MAX_N 1000

int tcCnt;
int N;
double cost_rate;

struct edge_type {
	int u;
	int v;
	double cost;
};

pair<int, int> node[MAX_N];   
int parent[MAX_N];

int findset(int u) {
	int tmp = u;
	while (parent[tmp]!= tmp)
		tmp = parent[tmp];

	return tmp;
}

bool compare(edge_type& edge1, edge_type& edge2) {
	return edge1.cost < edge2.cost;
}

int solve(int x, int y, int sum) {
	edge_type edge[MAX_N *(MAX_N-1)/2];
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (i + 1); ++j) {
			edge[cnt].u = i;
			edge[cnt].v = j;
			if (i == j) edge[cnt].cost = INF;
			else edge[cnt].cost = (pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2)) * cost_rate;
			++cnt;
		}
	}
	sort(edge, edge + N * (N - 1) / 2, compare);
	for (int i = 0; i < N; ++i)
		parent[i] = i;

	int sum = 0, select_cnt = 0;
	for (int i = 0; select_cnt < N ; ++i) {
		int u = edge[i].u;
		int v = edge[i].v;
		if (findset(u) == findset(v)) continue;
		else parent[findset(u)] = findset(v);
		sum += edge[i].cost;
		++select_cnt;
	}
	return sum;
}

int main() {
	//freopen("test_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> node[i].first;
		for (int i = 0; i < N; ++i)
			cin >> node[i].second;
		cin >> cost_rate;

		cout << "#" << t + 1 << ' ' << solve(0, 0, 0) << endl;
	}
	return 0;
}