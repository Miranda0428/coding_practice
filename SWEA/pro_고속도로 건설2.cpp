#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 50000
#define MAX_E 200000
#define INF 1000000

typedef pair<int, int> pii;

int tcCnt;
int N, edge;

//int Prim(int *graph[]) {
//    priority_queue < pii, vector<pii>, greater<pii> > pq;
//
//    bool visited[MAX_N] = { false };
//
//    visited[0] = true;
//    for (int next = 0; next < N; ++next)
//        pq.push(make_pair(graph[0][next], next));
//
//    int sum = 0;
//    while (!pq.empty()) {
//        int curr = pq.top().second;
//        int weight = pq.top().first;
//        pq.pop();
//
//        if (visited[curr] == true) continue;
//        visited[curr] = true;
//        sum += weight;
//
//        for (int next = 0; next < N; ++next)
//            pq.push(make_pair(graph[curr][next], next));
//    }
//    return sum;
//}

struct edge_type {
    int cost;
    int u;
    int v;
};

edge_type edge_arr[MAX_E];
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

/* 아래와 같이 sort를 이용하면 런타임 에러가 난다.
 priority queue를 사용하여 연산시간을 줄여야 한다.*/
//int Kruscal() {
//    sort(edge_arr, edge_arr + edge, compare);
//    for (int i = 1; i <= N; ++i)
//        Parent[i] = i;
//
//    int sum = 0, select_cnt = 0;
//    for (int i = 0; i < edge; ++i) {
//        int u = edge_arr[i].u;
//        int v = edge_arr[i].v;
//        if (findset(u) == findset(v)) continue;
//        else Parent[findset(u)] = findset(v);
//        sum += edge_arr[i].cost;
//        if (++select_cnt >= N-1) break;
//    }
//    return sum;
//}

int Kruscal(priority_queue<edge_type> pq) {
    for (int i = 1; i <= N; ++i)
        Parent[i] = i;

    int sum = 0;
    while(!pq.empty()){
        int u = pq.top().u;
        int v = pq.top().v;
        if (findset(u) == findset(v)) continue;
        else Parent[findset(u)] = findset(v);
        sum += pq.top().cost;
        pq.pop();
    }
    return sum;
}


void make_graph(int *graph[]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}

int main(){
    //freopen("test_input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for(int t=0; t<tcCnt; ++t){
        cin >> N;
        cin >> edge;
//        int **graph;
//        graph = new int*[N];
//        for (int i = 0; i < N; i++)
//            graph[i] = new int[N];
//        make_graph(graph);
//        for(int i=0; i < edge; ++i){
//            int x, y, cost;
//            cin >> x >> y >> cost;
//            graph[x-1][y-1] =  graph[y-1][x-1] = cost;
//        }
        priority_queue<edge_type> pq;
        
        for(int i=0; i < edge; ++i){
            cin >> edge_arr[i].u >> edge_arr[i].v >> edge_arr[i].cost;
            pq.push(edge_arr[i]);
        }
            
        cout << "#" << t + 1 << ' ' << Kruscal(pq) << endl;
        //delete[] graph;
    }
    return 0;
}
    
    //Prim();
    //Kruscal();
