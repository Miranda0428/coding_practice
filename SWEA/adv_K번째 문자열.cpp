// 방법 1. set에 부분집합을 넣어서 K번째 문자열을 뽑는 코드(set_solve)
// 방법 2. Trie를 구현하고, 각각의 노드에 해당 노드로 시작하는 단어의 개수(cnt)와 해당 노드로 끝나는 단어의 존재 여부(end)를 저장함. 
//        모든 단어를 Trie에 넣고, cnt가 K를 넘어가지 않도록 탐색(trie_solve)
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
	set<string> subsets;    // set은 넣는 순간 자동정렬(오름차순), 중복삭제됨
	
	// 부분집합 만들기
	for (int i = 0; i < string_size; ++i){
		string temp = { whole_string[i] };    // char → string
		subsets.insert(temp);

		for (int j = i + 1; j < string_size; j++)
		{
			temp += whole_string[j];          // string 붙이기
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