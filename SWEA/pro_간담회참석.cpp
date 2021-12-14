#include <iostream>
#include <queue>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 50001
#define MAX_M 500000
#define INF 1000000

int tcCnt;
int N, M, X;

vector<pair<int, int>> edge1[MAX_N];
vector<pair<int, int>> edge2[MAX_N];
int Dist1[MAX_N];
int Dist2[MAX_N];

//struct pq_compare {
//    bool operator()(const pair<int, int> edge1, pair<int, int> edge2) {
//        return edge1.second > edge2.second;
//    }
//};

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

        if (Dist[current] < distance) continue;
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

int solve() {
    int ret = 0;
    // X에서 각 노드로 최단거리
    dijkstra(X, Dist1, edge1);
    dijkstra(X, Dist2, edge2);
    for (int i = 1; i <= N; ++i) {
        int tmp = Dist1[i] + Dist2[i];
        if (ret < tmp) ret = tmp;
    }
    return ret;
    //for (int node = 1; node <= N; ++node) {
    //    if (node == X) continue;
    //    // 각 노드를 시작점으로 하는 최단거리
    //    dijkstra(node, Dist2);
    //    int tmp = Dist1[node] + Dist2[X];
    //    if (ret < tmp)
    //        ret = tmp;
    //}
    //return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> N >> M >> X;
        int x, y, z;
        for (int i = 0; i < M; ++i) {
            cin >> x >> y >> z;
            edge1[x].push_back(make_pair(z, y));
            edge2[y].push_back(make_pair(z, x));
        }
        cout << "#" << t + 1 << ' ' << solve() << endl;
        // edge들 초기화를 안해줘서 테스트 케이스가 늘어날 때마다 계혹 push_back 함-_-
        // 같은 실수의 반복...
        for (int i = 1; i <= N; ++i) {
            edge1[i].clear();
            edge2[i].clear();
        }
    }
    return 0;
}