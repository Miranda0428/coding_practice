#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
#define INF 1e9

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
	int& ret = memo[num][cnt];
	if (ret != -1) return ret;

	if (cnt == 0) return ret = num;

	ret = 0;
	for (int i = 0; i < num_card - 1; ++i) {
		for (int j = i + 1; j < num_card; ++j) {
			int tmp = solve(swap_card(num, i, j), cnt - 1);
			//���ڰ� num�̰� ���� ��ȯȽ���� cnt�� ��, �ִ밪�� memo[num][cnt]�� ���̰� ��
			if (tmp > ret) ret = tmp;
		}
	}
	return ret;
}
	
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> number >> num_exchange;
		// ������ �ڸ��� ����
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

		cout << "#" << t + 1 << ' ' << solve(number, num_exchange) << endl;
	}	
		return 0;
}