//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//
//#pragma warning(disable:4996)
//using namespace std;
//
//#define MAX_N 50000
//#define MAX_M 150000
//
//int tcCnt;
//int N, M;
//vector<int> graph[MAX_N];
//vector<int> result;
//bool visit[MAX_N];
//
//void dfs(int node) {
//    visit[node] = true;
//    int len = graph[node].size();
//    for (int i = 0; i < len; ++i) {
//        int child = graph[node][0];
//        if (!visit[child])
//            dfs(child);
//        else {
//            graph[node].erase(graph[node].begin());
//            break;
//        }
//        if (graph[child].empty()) {
//            result.push_back(child);
//            graph[node].erase(graph[node].begin());
//        }
//    }
//}
//
//void solve() {
//    for (int i = 1; i <= N; ++i)
//        visit[i] = false;
//
//    for (int j = 1; j <= N;++j) {
//        if (!visit[j]) {
//            dfs(j);
//            result.push_back(j);
//        }
//    }
//
//    reverse(result.begin(), result.end());
//    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
//        cout << *iter << ' ';
//    }
//    cout << endl;
//
//    for (int i = 0; i <= N; ++i)
//        graph[i].clear();
//    result.clear();
//}
//
//int main() {
//    freopen("sample_input.txt", "r", stdin);
//    cin >> tcCnt;
//    int x, y;
//    for (int t = 0; t < tcCnt; t++) {
//        cin >> N >> M;
//        for (int i = 0; i < M; ++i) {
//            cin >> x >> y;
//            graph[x].push_back(y);
//        }
//        cout << "#" << t + 1 << ' ';
//        solve();
//        cout << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 32001
#define MAX_M 100001

int tcCnt;
int N, M;
vector<int> graph[MAX_N];
vector<int> result;
bool visit[MAX_N];

void dfs(int node) {
    visit[node] = true;
    for (vector<int>::iterator iter = graph[node].begin(); iter != graph[node].end(); iter++) {
        int there = *iter;
        if (!visit[there])
            dfs(there);
    }
    result.push_back(node);
}

void dfs2(int node) {
    visit[node] = true;
    for (vector<int>::iterator iter = graph[node].begin(); iter != graph[node].end(); ++iter) {
        int child = *iter;
        if (!visit[child])
            dfs(child);
    }   
    result.push_back(node);
}


void solve() {
    for (int i = 0; i <= N; ++i)
        visit[i] = false;

    for (int j = 1; j <= N;++j) 
        if (!visit[j]) 
            dfs2(j);            
       
    reverse(result.begin(), result.end());
    for (vector<int>::iterator iter = result.begin(); iter!=result.end() ; iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    for (int i = 0; i <= N; ++i)
        graph[i].clear();
    result.clear();
}

int main() {
    freopen("sample_input.txt", "r", stdin);
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    solve();
    return 0;
}