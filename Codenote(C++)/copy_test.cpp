#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	char arr[2][100] = { "Hello world!", "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678" };
	char tmp[100];

	for (int i = 0; i < 2; ++i) {
		copy(arr[i], arr[i] + 100, tmp);
		cout << tmp << endl;
	}
}