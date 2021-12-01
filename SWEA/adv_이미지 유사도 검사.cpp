#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 501

int tcCnt;
int length;
char str_A[MAX_N];
char str_B[MAX_N];

int LCS[MAX_N][MAX_N]={0,};

double solve(){

    for(int i = 1; i <=length; ++i){
        for(int j = 1; j<=length; ++j){
            if(str_A[i-1] == str_B[j-1]) 
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else 
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    return (double)LCS[length][length]/length * 100;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for(int t = 0; t < tcCnt; ++t){
        cin >> length;
        cin >> str_A;
        cin >> str_B;
        cout << "#" << t+1 << ' ' ;
        printf("%.2f", solve());
        cout << endl;
    }
    return 0;
}
