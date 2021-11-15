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
			printf(" %.10f", solve(i));         // �Ҽ��� ���� 10�ڸ� ������ ���
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

	for(int k = 0; k < 200; k++) {             // �������� ������� ������ 1e-12 ���Ͽ��� �Ѵٴ� ������ �ִµ�
		ret = (start + end) / 2;			   // 200�� ���� �̺�Ž���� �ϸ� ���� ������ �����Ѵ�.
		left_power = 0;                        // ������� ���� 1e-12�� �ǵ��� �ϴ� �ͺ��� ����Ž���� ����� �ϴ� ���� ����.
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