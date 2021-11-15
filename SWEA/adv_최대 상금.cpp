/* 다시 풀어보기 : 메모이제이션을 활용한 완전탐색으로 풀어야함 */
/* 메모이제이션을 이해하지 못하였음 */

#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;
int tcCnt;
int number;
int num_exchange;
int num_card;
int memo[1000000][20];

int swap_card(int number, int a, int b) {
	int tmp = number;
	int card[6];

	if (a == b) return number;

	for(int i = 0; i < num_card; ++i){
		card[i] = tmp % 10;
		tmp = tmp / 10;
	}
	swap(card[a], card[b]);

	tmp = card[num_card - 1];
	for (int j = num_card - 2; j >= 0; --j) {
		tmp = tmp * 10 + card[j];
	};
	return tmp;
}

int solve(int num, int cnt) {

	int tmp = 0;
	int& ret = memo[num][cnt];
	if (ret != -1) return ret;

	if (cnt == 0) return num;

	for (int i = 0; i < num_card - 1; ++i) {
		for (int j = 1; j < num_card; ++j) {
			tmp = solve(swap_card(num, i, j), cnt - 1);
			if (tmp > ret) ret = tmp;
		}
	}
	return ret;
}
	

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	int* answer = new int[tcCnt + 1];
	for (int t = 0; t < tcCnt; ++t) {
		cin >> number >> num_exchange;
		// 숫자의 자리수 세기
		int num = number;
		int cnt = 0;
		while (num) {
			num = num / 10;
			cnt++;
		}
		num_card = cnt;

		for (int i = 0; i < 1000000; ++i)
			for (int j = 0; j < 20; ++j)
				memo[i][j] = -1;

		answer[t] = solve(number, num_exchange);
	}
	for (int t = 0; t < tcCnt; ++t)
		cout << "#" << t + 1 << ' ' << answer[t] << endl;
	delete[] answer;
	return 0;
}