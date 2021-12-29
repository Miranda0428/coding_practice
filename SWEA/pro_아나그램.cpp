/*정리 필요*/
#include <iostream>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

int tcCnt;
string s1, s2;

int solve() {
    int cnt = 0; int flag = 0;
    int s1_len = s1.size();
    int s2_len = s2.size();
    
    int s1_xor = 0; int s2_xor = 0;
    int s1_freq[26] = { 0, };
    int s2_freq[26] = { 0, };

    for (int i = 0; i < s1_len; ++i) {
        s1_xor ^= s1[i];
        s1_freq[s1[i] - 'a']++;
    }

    for (int j = 0; j < s1_len; ++j) {
        s2_xor ^= s2[j];
    }
        
    for (int i = 0; i <= (s2_len - s1_len); ++i) {
        if (s1_xor == s2_xor) {
            for (int k = i; k < i + s1_len; ++k)
                s2_freq[s2[k] - 'a']++;
            for (int j = 0; j < 26; ++j) {
                if (s1_freq[j] != s2_freq[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                cnt++;
            else
                flag = 0;
            memset(s2_freq, 0x00, sizeof(int) * 26);
        }        
        s2_xor ^= s2[i]; 
        s2_xor ^= s2[i + s1_len];
    }   
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for(int t=0; t<tcCnt; t++){
        cin >> s1;
        cin >> s2;
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}