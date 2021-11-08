#include <iostream>
#include <algorithm>

using namespace std;

int Hashtable[7000];
int row, col;
char arr[2000][2000];
int answer[10];
int solve();

int main(int argc, char **argv) {
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
		cout << "#" << t + 1 << ' ' << answer[t] << endl;
	return 0;
}
/* 2차원 배열 arr[100][100]을 함수 인자로 전달하기 위해서는 char arr[][100] 또는
   char (*arr)[100] 으로 전달해야 한다. */
void hex_to_binarr(char (*arr)[2000]) {
	char hex_value[16][5] = { "0000", "0001", "0010", "0011", "0100", "0101", "0111",
		"1000", "1001", "1010", "1011", "1100", "1101", "1111" };
	char tmp[2000];
	char a = 0;
	for (int i = 0; i < row; ++i) {
		copy(arr[i], arr[i]+col, tmp);
		for (int j = 0; j < col; ++j) {
			if (tmp[j] >= 'A')                 //16 진수를 10진수를 바꿔서 hex_value의 인덱스로 사용한다.
				a = tmp[j] - 'A' + 10;
			else
				a = tmp[j] - '0';
			for (int k = 0; k < 4; ++k)
				arr[i][j * 4 + k] = hex_value[a][k];
		}
	}
}

int calscale(char *arr, int j) {
	int count = 0;
	
	for (int c = j; ; --c) {
		if (arr[c] != arr[c - 1]) count++;
		if (count == 4) {
			return (j - c + 1) / 7;
		}
	}
}

int* parse(int i, int start, int scale) {
	int code[8] = { 0, };
	int idx = 0;
	int scale_times = 7 * scale;
	for (int k = start; ; k += scale_times) {
		int key = 0;
		int cnt = 1;
		for (int a = 0; a < scale_times; ++a) {
			if (arr[i][k + a] == arr[i][k + a + 1])
				++cnt;
			else {
				cnt /= scale;
				key = key * 10 + cnt;
				cnt = 1;
			}
		}
		code[idx++] = Hashtable[key];
	}
	return code;
}

int solve() {
	int* code;
	int code_arr[8];
	int flag = 0; 
	int sum = 0;
	int scale = 0;
	int start_col = 0;

	code = code_arr;
	hex_to_binarr(arr);

	for (int i = 0; i < row; ++i) {
		for (int j = col - 1; j >= 55; --j) {
			if (arr[i][j] == '1') {
				flag = true;
				scale = calscale(arr[i], j);
				start_col = j - 56 * scale + 1;
				code = parse(i, start_col, scale);   // hashtable을 리턴하는 함수
				for (int k=0; k < 8; ++k)
					if (code[k] < 0){
						flag = false;
						break;				
				}
				if (flag) {
					for (int a = i + 1; a < row; a++)
						for (int b = start_col; b < j + 1; ++b) {
							if (arr[i][b] == arr[a][b])
								arr[a][b] = '0';
							else {
								a = row;
								break;
							}
						}

					if (((code[0] + code[2] + code[4] + code[6]) * 3 + (code[1] + code[3] + code[5] + code[7])) % 10 == 0) {
						for (int i = 0; i < 8; ++i)
							sum += code[i];
					}
				}
			}
			j = start_col - 1;
		}
	}
	return sum;
}