#include <iostream>

using namespace std;

int Hashtable[7000];
int row, col;
char arr[50][100];
int answer[10];
int solve();

int main() {
	for (int i = 0; i < 7000; ++i)
		Hashtable[i] = -1;
	Hashtable[3211] = 0;
	Hashtable[2221] = 1;
	Hashtable[2122] = 2;
	Hashtable[1411] = 3;
	Hashtable[1132] = 4;
	Hashtable[1231] = 5;
	Hashtable[1114] = 6;
	Hashtable[1312] = 7;
	Hashtable[1213] = 8;
	Hashtable[3112] = 9;
	int tcCnt;
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> row >> col;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				cin >> arr[i][j];
		answer[t] = solve();
	}
	cout << endl;
	for (int t = 0; t < tcCnt; ++t)
		cout << "#" << t+1 << ' ' << answer[t] << endl;
	return 0;
}

int solve() {
	int code[8] = { 0, };
	int flag = 0;
	int sum = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = col - 1; j >= 55; --j) {
			if (arr[i][j] == '1') {
				flag = true;
				int idx = 0;
				for (int k = j - 55; k <= j - 6; k = k + 7) {
					int key = 0;
					int cnt = 1;
					for (int a = 0; a < 7; ++a) {
						if (arr[i][k + a] == arr[i][k + a + 1])
							++cnt;
						else {
							key = key * 10;
							key = key + cnt;
							cnt = 1;
						}
					}
					code[idx++] = Hashtable[key];
					if (Hashtable[key] < 0) {
						flag = false;
						break;
					}
				}
				if (flag)
					break;
			}			
		}
	}

	if (((code[0] + code[2] + code[4] + code[6]) * 3 + (code[1] + code[3] + code[5] + code[7])) % 10 == 0) {
		for (int i = 0; i < 8; ++i)
			sum += code[i];
	}

	return sum;
}