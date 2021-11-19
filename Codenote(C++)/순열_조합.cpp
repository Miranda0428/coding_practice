/* 순열(solve_1), 조합(solve_2) 에 해당하는 완전탐색을 재귀적으로 구현하기
   순열 - 1,2,3,4 중 2개 숫자를 이용하여 최대값 출력하기
   조합 - 2개를 더해서 만들 수 있는 최대값 출력하기(재귀가 아니고 bit 부분집합으로도 풀 수 있음) */
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int nums[4] = { 1, 2, 3, 4 };

// 순열
int solve_1(int cnt, int used, int val) {
	if (cnt == 2) return val;

	int ret = 0; // 최대값 구할때는 0, 최소값 구할때는 INF
	for (int i = 0; i < 4; ++i) {
		if (used & (1 << i)) continue;
		int tmp = solve_1(cnt + 1, used | (1 << i), val * 10 + nums[i]);
		if (tmp > ret)
			ret = tmp;
	}
	return ret;
}

// 조합
int solve_2(int cnt, int pos, int val) {
	if (cnt == 2) return val;
	if (pos == 4) return -1;

	int ret = 0;
	int tmp;

	// 지금 위치의 수를 선택함
	tmp = solve_2(cnt + 1, pos + 1, val + nums[pos]);
	if (tmp > ret)
		ret = tmp;

	// 지금 위치의 수를 선택안함
	tmp = solve_2(cnt, pos + 1, val);
	if (tmp > ret)
		ret = tmp;

	return ret;
}

int main() {
	cout << solve_1(0, 0, 0) << endl;
	cout << solve_2(0, 0, 0) << endl;
	return 0;
}