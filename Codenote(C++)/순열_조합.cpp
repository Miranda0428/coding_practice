/* ����(solve_1), ����(solve_2) �� �ش��ϴ� ����Ž���� ��������� �����ϱ�
   ���� - 1,2,3,4 �� 2�� ���ڸ� �̿��Ͽ� �ִ밪 ����ϱ�
   ���� - 2���� ���ؼ� ���� �� �ִ� �ִ밪 ����ϱ�(��Ͱ� �ƴϰ� bit �κ��������ε� Ǯ �� ����) */
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int nums[4] = { 1, 2, 3, 4 };

// ����
int solve_1(int cnt, int used, int val) {
	if (cnt == 2) return val;

	int ret = 0; // �ִ밪 ���Ҷ��� 0, �ּҰ� ���Ҷ��� INF
	for (int i = 0; i < 4; ++i) {
		if (used & (1 << i)) continue;
		int tmp = solve_1(cnt + 1, used | (1 << i), val * 10 + nums[i]);
		if (tmp > ret)
			ret = tmp;
	}
	return ret;
}

// ����
int solve_2(int cnt, int pos, int val) {
	if (cnt == 2) return val;
	if (pos == 4) return -1;

	int ret = 0;
	int tmp;

	// ���� ��ġ�� ���� ������
	tmp = solve_2(cnt + 1, pos + 1, val + nums[pos]);
	if (tmp > ret)
		ret = tmp;

	// ���� ��ġ�� ���� ���þ���
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