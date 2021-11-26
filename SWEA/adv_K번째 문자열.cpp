// ��� 1. set�� �κ������� �־ K��° ���ڿ��� �̴� �ڵ�(set_solve)
// ��� 2. Trie�� �����ϰ�, ������ ��忡 �ش� ���� �����ϴ� �ܾ��� ����(cnt)�� �ش� ���� ������ �ܾ��� ���� ����(end)�� ������. 
//        ��� �ܾ Trie�� �ְ�, cnt�� K�� �Ѿ�� �ʵ��� Ž��(trie_solve)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#pragma warning(disable:4996)

int tcCnt;
int K;
string whole_string;
int string_size;

string set_solve() {
	set<string> subsets;    // set�� �ִ� ���� �ڵ�����(��������), �ߺ�������
	
	// �κ����� �����
	for (int i = 0; i < string_size; ++i){
		string temp = { whole_string[i] };    // char �� string
		subsets.insert(temp);

		for (int j = i + 1; j < string_size; j++)
		{
			temp += whole_string[j];          // string ���̱�
			subsets.insert(temp);
		}
	}

	set<string>::iterator iter;
	int i;
	bool flag = 0;
	string tmp;

	for (iter = subsets.begin(), i = 1; iter != subsets.end(); iter++, i++)
	{
		if (i == K) {
			tmp = *iter;
			flag = 1;
			break;
		}
	}
	if (!flag) tmp = "none\n";
	return tmp;
}

int main() {
	//freopen("test_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; ++t) {
		cin >> K;
		cin >> whole_string;
		string_size = whole_string.size();
        cout << "#" << t + 1 << ' ' << set_solve() << endl;
	}
	return 0;
}