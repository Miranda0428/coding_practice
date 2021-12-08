#include <iostream>
#include <algorithm>
#include <string>

#pragma warning(disable:4996)
using namespace std;

#define MAX_N 251

int tcCnt;
int N;
string D[MAX_N];

string add(string& s1, string& s2){
    string result(max(s1.size(), s2.size()), '0');
    bool carry = false;
    for (int i = 0; i < result.size(); i++){
        int temp = carry;
        carry = false;
        if (i < s1.size())
            temp += s1[s1.size() - i - 1] - '0';
        if (i < s2.size())
            temp += s2[s2.size() - i - 1] - '0';
        if (temp >= 10){
            carry = true;
            temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }
    if (carry)
        result.insert(result.begin(), '1');
    return result;
}

string mul(string& s1, string& s2){
    string result = "0";
    for (int i = 0; i < s2.size(); i++){
        string line(s1);
        int carry = 0;
        for (int j = s1.size() - 1; j >= 0; j--)
        {
            int temp = carry;
            carry = 0;
            temp += (s1[j] - '0') * (s2[s2.size() - i - 1] - '0');
            if (temp >= 10)
            {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }
        if (carry > 0)
            line.insert(line.begin(), carry + '0');
        line += string(i, '0');
        result = add(result, line);
    }
    return result;
}

string solve() {
    D[1] = "1";
    D[2] = "3";
    string two = "2";

    if (N > 2) {
        for (int i = 3; i <= N; ++i) {
            string tmp;
            tmp = mul(D[i - 2], two);
            D[i] = add(tmp, D[i - 1]);
        }
    }
    return D[N];
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 0; t < tcCnt; ++t) {
        cin >> N;
        for (int i = 0; i < N; ++i) D[i] = '0';
        cout << "#" << t + 1 << ' ' << solve() << endl;
    }
    return 0;
}