// 바텀업 DP memoization으로 풀어야 한다.
// 자신의 2^k 번째 조상을 저장하는 배열을 만든다.

#include <iostream>
#include <stdio.h>

#pragma warning(disable:4996)

using namespace std;

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

int V, E, Tree[10001][2], Parent[10001], Depth[10001], Size[10001];
int traversal(int node, int depth);
int lca(int n1, int n2);

int main(int argc, char** argv)
{
    int tcCnt, n1, n2;

    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t)
    {
        cin >> V >> E >> n1 >> n2;
        for (int i = 0; i < V; ++i)
            Tree[i][0] = Tree[i][1] = 0;

        for (int i = 0; i < E; ++i) {
            int p, c;
            cin >> p >> c;
            if (Tree[p][0] == 0) Tree[p][0] = c;
            else Tree[p][1] = c;
            Parent[c] = p;
        }
        traversal(1, 0);
        int anc = lca(n1, n2);

        cout << "#" << t + 1 << ' ' << anc << ' ' << Size[anc] << endl;
    }
    return 0;
}


int traversal(int node, int depth) {
    int cnt = 0;
    if (node != 0) {
        cnt++;
        cnt += traversal(Tree[node][0], depth + 1);
        cnt += traversal(Tree[node][1], depth + 1);
    }

    Depth[node] = depth;
    Size[node] = cnt;

    return cnt;
}

int lca(int n1, int n2) {

    int u = Depth[n1] > Depth[n2] ? n1 : n2;
    int v = Depth[n1] > Depth[n2] ? n2 : n1;

    int diff = Depth[u] - Depth[v];

    for (int i = diff; i > 0; --i)
        u = Parent[u];

    while (u != v) {
        u = Parent[u];
        v = Parent[v];
    }
    return u;
}