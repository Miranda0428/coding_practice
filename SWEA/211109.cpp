/* 벡터 컨테이너를 만들어서 STL을 활용해서 문제를 풀어보자.*/
#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int int_to_card(int* card, int numbers) {
	int tmp_num = numbers;
	int i = 0;
	while(tmp_num) {
		card[i] = tmp_num % 10;
		tmp_num = card[i];
		i++;
	}
	return i;
}

int solve(int numbers, int num_exchange) {
	int max_num = 0;
	int card[6];
	int num_card = int_to_card(card, numbers);    // 숫자를 카드로 바꾸고 카드 장수 리턴

	int max_card, min_card;
	int max_idx, min_idx;
	//int tmp = 0;

	for (int i = num_exchange; i > 0; --i) {
		for (int j = 0; j < num_card - 1; j++) {
			if (card[j] > card[j + 1]) {
				max_card = card[j];
				max_idx = j;
			}
			else {
				min_card = card[j];
				min_idx = j;
			}				
		}
		swap(card[max_idx], card[min_idx]);
	}
	return max_num;
}

int main(int argc, char** argv) {
	int tcCnt;
	int numbers;
	int num_exchange;
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	int* answer = new int[tcCnt];
	for (int t = 0; t < tcCnt; ++t) {
		cin >> numbers >> num_exchange;
		answer[t] = solve(numbers, num_exchange);
	}
	for (int t = 1; t <= tcCnt; ++t)
		cout << "#" << t  << ' ' << answer[t] << endl;
	delete[] answer;
	return 0;
}
