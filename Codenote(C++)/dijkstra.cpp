/*최단 경로 찾기 - Dijkstra, 벨만-포드, 플로이드 워셜*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define INF 2147483647;

typedef pair<int, int> pii;
int N, graph[MAX_N][MAX_N];
int Dist[MAX_N];

void dijkstra(int start, int* Dist, vector<pair<int, int>>* edge) {
    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= N; ++i)
        Dist[i] = INF;
    Dist[start] = 0;

    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
	
        if (Dist[current] < distance) continue;  // 이렇게 하면 visit 배열이 필요없다.
        for (int i = 0; i < (int)edge[current].size(); ++i) {
            int nextdist = distance + edge[current][i].first;
            int there = edge[current][i].second;
            if (Dist[there] > nextdist) {
                Dist[there] = nextdist;
                pq.push(make_pair(-nextdist, there));
            }
        }
    }
}

int dijkstra(int src, int dst) {
	// priority_queue<T, Container, Compare>
	// 원하는 자료형 및 클래스 T를 통해 생성. 여기서 Container는 vector와 같은 컨테이너, Compare는 비교함수 클래스
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
