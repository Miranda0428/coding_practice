/*의외로 싱거운 문제, 50분만에 풀었다.
 
 그러나 stl의 힘은 강력하다!!(stl sting으로 다 품 - stl 못 썼다면 매우 귀찮고 빡셌을 것)*/

#include <iostream>
#include <algorithm>
#include <string>              

using namespace std;

#pragma warning(disable:4996)
#define MAX_N 400

int tcCnt;
int N;
string whole_string;
int string_size;

bool compare(string& A, string& B) {
	int cnt = 0;
	while (cnt < string_size) {
		if (A[cnt] == '/n') return true;
		if (B[cnt] == '/n') return false;

		if (A[cnt] < B[cnt]) return true;
		else if (A[cnt] > B[cnt]) return false;
		else ++cnt; //(A[cnt] == B[cnt])
	}
	return true;
}

string solve() {
	string sub_string[MAX_N];

	for (int i = 0; i < string_size ; ++i) {
		//sub_string[i].assign(whole_string, whole_string.end(), i);
		sub_string[i].assign(whole_string, 0, i + 1);
		reverse(sub_string[i].begin(), sub_string[i].end());
	}
	sort(sub_string, sub_string + string_size, compare);

	return sub_string[N-1];
}

int main() {
	//freopen("test_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> N;
		cin >> whole_string;
		string_size = whole_string.size();
		reverse(whole_string.begin(), whole_string.end());
		cout << "#" << t + 1 << ' ' << solve() << endl;
	}
	return 0;
}