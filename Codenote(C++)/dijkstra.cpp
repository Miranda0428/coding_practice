/*�ִ� ��� ã�� - Dijkstra, ����-����, �÷��̵� ����*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define INF 2147483647;

typedef pair<int, int> pii;
int N, graph[MAX_N][MAX_N];
int Dist[MAX_N];

int dijkstra(int src, int dst) {
	// priority_queue<T, Container, Compare>
	// ���ϴ� �ڷ��� �� Ŭ���� T�� ���� ����. ���⼭ Container�� vector�� ���� �����̳�, Compare�� ���Լ� Ŭ����
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	bool visited[MAX_N] = { false };
	for (int i = 0; i < N; ++i) Dist[i] = INF;
	Dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int curr = pq.top().second;
		if (curr == dst) return pq.top().first;
		pq.pop();
		if (visited[curr] == true) continue;
		visited[curr] = true;
		for (int next = 0; next < N; ++next) {
			if (Dist[next] > Dist[curr] + graph[curr][next]) {

				Dist[next] = Dist[curr] + graph[curr][next];
				pq.push(make_pair(graph[curr][next], next));
			}
		}
	}
	return INF;
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
	int src = 0, dst = 0;

	make_graph();

	dijkstra(src, dst);

	return 0;
}