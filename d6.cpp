#include <bits/stdc++.h>
#define MESSAGE_LEN 14 // change to 4 for part 1, and 14 for part 2
using namespace std;

int main() {
	string s;
	cin >> s;

	cout << s << endl;
	for (int i = 0; i < s.length() - MESSAGE_LEN - 1; i++) {
		string ss = s.substr(i, MESSAGE_LEN);
		cout << ss << endl;
		set<char> a;
		for (int j = 0; j < ss.length(); j++) {
			if (a.count(ss[j])) {
				goto goNext;
			}
			a.insert(ss[j]);
		}
		cout << (i + MESSAGE_LEN) << endl;
		return 1;
	goNext : {}
	}
	return 1;
}