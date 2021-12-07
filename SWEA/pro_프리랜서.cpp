#include <iostream>
#include <algorithm>

using namespace std;
int tcCnt;
int task, day;
int start, end_day;
int money;

struct WORK{
    int start;
    int end_day;
    int money;
}work[10000];

int opt[10000] = {0, };
int p[10000] = {0, };

bool compare(WORK &work1, WORK &work2){
    if(work1.end_day < work2.end_day)
        return true;
    else
        return false;
}

int solve(){
    sort(work, work+task, compare);
    //opt[0] = work[0].money;
    p[0] = 0;
    for(int i=1; i<task; ++i){
        for(int j=0; j<i; ++j){
            if(work[j].end_day < work[i].start)
                p[i] = max(p[i], work[j].end_day);
        }
    }
    
    int i;
    for(i = 0; i<work[0].end_day; ++i)
        opt[i] = 0;
    
    for(int j=i; j<day; ++j){
        opt[j] = max(opt[j-1],  work[j-i].money + opt[p[j-i]]);
    }
    return opt[day-1];
}

int main(){
    cin >> tcCnt;
    for(int t=0; t<tcCnt; ++t){
        cin >> task >> day;
        for(int i=0; i<task; ++i)
            cin >> work[i].start >> work[i].end_day >> work[i].money;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}
