/*최소신장트리 찾기 - Prim, Kruscal 알고리즘이 있다.*/
/*Prim : 노드 기준, Kruscal : 간선 기준*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100

typedef pair<int, int> pii;

int N, graph[MAX_N][MAX_N];

int Prim() {
	// priority_queue<T, Container, Compare>
	// 원하는 자료형 및 클래스 T를 통해 생성. 여기서 Container는 vector와 같은 컨테이너, Compare는 비교함수 클래스
	priority_queue < pii, vector<pii>, greater<pii> > pq;

	bool visited[MAX_N] = { false };

	visited[0] = true;
	for (int next = 0; next < MAX_N; ++next)
		pq.push(make_pair(graph[0][next], next));

	int sum = 0;
	while (!pq.empty()) {
		int curr = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (visited[curr] == true) continue;
		visited[curr] = true;
		sum += weight;

		for (int next = 0; next < N; ++next)			
			pq.push(make_pair(graph[curr][next], next));
	}
	return sum;
}

struct edge_type {
	int u;
	int v;
	int cost;
};
edge_type edge_arr[MAX_N * (MAX_N - 1) / 2];
int edge_cnt;
int Parent[MAX_N];

bool compare(edge_type& edge1, edge_type& edge2) {
	return edge1.cost < edge2.cost;
}

int findset(int node) {
	int v = node;
	while (v != Parent[v])
		v = Parent[v];

	return Parent[v];
}

int Kruscal() {
	sort(edge_arr, edge_arr + (MAX_N * (MAX_N - 1) / 2), compare);
	for (int i = 0; i < MAX_N; ++i)
		Parent[i] = i;

	int sum = 0, select_cnt = 0;
	for (int i = 0; i < edge_cnt; ++i) {
		int u = edge_arr[i].u;
		int v = edge_arr[i].v;
		if (findset(u) == findset(v)) continue;
		else Parent[findset(u)] = findset(v);
		sum += edge_arr[i].cost;
		if (++select_cnt >= N-1) break;
	}
	return sum;
}


void make_graph() {

	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			if (i == j) graph[i][j] == 0;
			else graph[i][j] = -1;
		}
	}
}

int main(int argc, char** argv) {

	make_graph();

	Prim();
	Kruscal();

	return 0;
}