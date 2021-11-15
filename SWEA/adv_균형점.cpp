#include <iostream>
#include <stdio.h>

//#pragma warning(disable:4996)

using namespace std;

int tcCnt;
int num_balls;
double d_ball[10] = { 0, };
double w_ball[10] = { 0, };

double solve(int pos);

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	int* answer = new int[tcCnt + 1];
	for (int t = 0; t < tcCnt; ++t) {
		cin >> num_balls;
		for (int i = 0; i < num_balls; ++i)
			cin >> d_ball[i];
		for (int i = 0; i < num_balls; ++i)
			cin >> w_ball[i];

		cout << "#" << t + 1;
		for (int i = 0; i < num_balls - 1; ++i)
			printf(" %.10f", solve(i));         // 소수점 이하 10자리 까지만 출력
		cout << endl;
	}
	delete[] answer;
	return 0;
}

double solve(int pos) {
	double ret = 0;
	double left_power;
	double right_power;

	double start = d_ball[pos];
	double end = d_ball[pos+1];

	for(int k = 0; k < 200; k++) {             // 문제에서 정답과의 오차가 1e-12 이하여야 한다는 조건이 있는데
		ret = (start + end) / 2;			   // 200번 정도 이분탐색을 하면 위의 조건을 만족한다.
		left_power = 0;                        // 정답과의 차가 1e-12가 되도록 하는 것보다 이진탐색을 충분히 하는 것이 좋다.
		right_power = 0;

		for (int j = pos; j >= 0; --j)
			left_power += w_ball[j] / ((d_ball[j] - ret) * (d_ball[j] - ret));
		for (int j = pos + 1; j < num_balls; ++j)
			right_power += w_ball[j] / ((d_ball[j] - ret) * (d_ball[j] - ret));

		if (left_power == right_power) return ret;
		if (left_power > right_power) start = ret;
		else end = ret;
	}
	return ret;
}