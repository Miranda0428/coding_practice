#include <iostream>
#include <algorithm>
#include <cmath>                  // pow�� ������ �ʿ��� ���

using namespace std;

#pragma warning(disable:4996)
#define INF 9223372036854775807   // 2^63 - 1
#define MAX_N 1000

int tcCnt;
int N;
double cost_rate;

struct edge_type {
	int u;
	int v;
	long long cost;
};

//pair<int, int> node[MAX_N];   
int node_x[MAX_N];
int node_y[MAX_N];
int parent[MAX_N];
// edge_type�� solve()�Լ��ȿ� �����ϸ� ������ ���ڶ� �������� �ȵ�
edge_type edge[MAX_N * (MAX_N - 1) / 2];     

int findset(int u) {
	int tmp = u;
	while (parent[tmp]!= tmp)
		tmp = parent[tmp];

	return tmp;
}

bool compare(edge_type& edge1, edge_type& edge2) {
	return edge1.cost < edge2.cost;
}

long long solve() {
	int cnt = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			edge[cnt].u = i;
			edge[cnt].v = j;
			if (i == j) edge[cnt].cost = INF;
			//else edge[cnt].cost = pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2);
			else edge[cnt].cost = pow(node_x[i] - node_x[j], 2) + pow(node_y[i] - node_y[j], 2);
			//else edge[cnt].cost = (node_x[i] - node_x[j])* (node_x[i] - node_x[j]) + (node_y[i] - node_y[j])* (node_y[i] - node_y[j]);
			++cnt;
		}
	}
	sort(edge, edge + cnt, compare);
	for (int i = 0; i < N; ++i)
		parent[i] = i;

	long long sum = 0;	int select_cnt = 0;
	for (int i = 0; select_cnt < (N - 1) ; ++i) {
		int u = edge[i].u;
		int v = edge[i].v;
		if (findset(u) == findset(v)) continue;
		else parent[findset(u)] = findset(v);
		sum += edge[i].cost;
		++select_cnt;
	}
	sum = sum * cost_rate + 0.5;                // �Ҽ��� ù° �ڸ����� �ݿø��� ���� ���ϱ� ���� 0.5�� ���Ѵ�.
	return (long long)sum;    
}

int main() {
	//freopen("test_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> node_x[i];
		for (int i = 0; i < N; ++i)
			cin >> node_y[i];
		cin >> cost_rate;

		cout << "#" << t + 1 << ' ' << solve() << endl;
	}
	return 0;
}