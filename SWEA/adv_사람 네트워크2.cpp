#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define INF 2000

int tcCnt;
int length;
int adj[MAX_N][MAX_N]={0,};
int D[MAX_N][MAX_N]={0,};

int solve(){
    for(int i=0; i<length; ++i){
        for(int j=0; j<length; ++j){
            if(i==j) D[i][j] = 0;
            else if((i!=j)&(adj[i][j]==0)) D[i][j] = INF;
            else D[i][j] = adj[i][j];
        }
    }
    
    for(int k=0; k<length; ++k)
        for(int i=0; i<length; ++i)
            for(int j=0; j<length; ++j)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    
    int sum = INF, tmp=0;
    for(int i=0; i<length; ++i){
        for(int j=0; j<length; ++j){
            tmp += D[i][j];
        }
        sum = min(sum, tmp);
        tmp = 0;
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for(int t = 0; t < tcCnt; ++t){
        cin >> length;
        for(int j=0; j<length; ++j)
            for(int k=0; k<length; ++k)
                cin >> adj[j][k];
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}
