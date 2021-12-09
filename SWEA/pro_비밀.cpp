/* 최장거리에 대해서 10이 나와야 하는데 나는 9가 나옴
내가 만든 test_case에서는 정상동작하기 때문에 뭐가 틀린지 모르겠음
제출해보면 20개중 14개가 맞았다고 한다.... */
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>

using namespace std;

#define MAX_N 11
#define MAX_K 30

int tcCnt;
int children, secret;
int mat[MAX_N][MAX_N];
int visit[MAX_N];

int dfs(int start){
    visit[start] = 1;
    int ret = 0;
    int flag = 0;
    for(int i = 1; i<=children; ++i){
        int cnt = 0;
        if((mat[start][i]!=0)&&(visit[i]==0)){
            flag = 1;
            cnt++;
            cnt += dfs(i);
            if(ret < cnt)
                ret = cnt;
        }
    }
    
    if(!flag) return 1;
    else
        return ret;
}

//private static void DFS(int current, int cost, boolean[] visited) {
//    visited[current] = true;
//    // 정점 [current]와 연결된 정점 리스트
//    List<Integer> to = adList.get(current);
//    for(int i = 0; i < to.size(); i++) {
//        int next = to.get(i);
//        if(!visited[next]) {
//            DFS(next, cost + 1, visited);
//            visited[next] = false;
//        }
//    }
//    visited[current] = false;
//    answer = Math.max(answer, cost);
//}

void solve(){
    int sum, longest = 0;
    for(int i=1; i<=children; ++i){
        sum = 0;
        for(int j=1; j<=children; ++j)
            sum += mat[i][j];
        cout << ' ' << sum;
        memset(visit, 0x00, sizeof(int)*MAX_N);
        int tmp = dfs(i);
        if(longest < tmp)
            longest = tmp;
    }
    cout << ' ' << longest;
}

int main(){
    //freopen("test_input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for(int t=0; t<tcCnt; ++t){
        memset(mat, 0x00, sizeof(int)*MAX_N*MAX_N);
        cin >> children >> secret;
        for(int i=0; i < secret; ++i){
            int num, x=0, y;
            cin >> num;
            for(int j=0; j<num; ++j){
                cin >> y;
                if(mat[x][y]==0) mat[x][y] = 1;
                x = y;
            }
        }
        cout << "#" << t + 1;
        solve();
        cout << endl;
    }
    return 0;
}

