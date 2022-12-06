#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> init() {
	vector<vector<char>> init(9);
	init[0] = vector<char>({'D', 'B', 'J', 'V'});
	init[1] = vector<char>({'P', 'V', 'B', 'W', 'R', 'D', 'F'});
	init[2] = vector<char>({'R', 'G', 'F', 'L', 'D', 'C', 'W', 'Q'});
	init[3] = vector<char>({'W', 'J', 'P', 'M', 'L', 'N', 'D', 'B'});
	init[4] = vector<char>({'H', 'N', 'B', 'P', 'C', 'S', 'Q'});
	init[5] = vector<char>({'R', 'D', 'B', 'S', 'N', 'G'});
	init[6] = vector<char>({'Z', 'B', 'P', 'M', 'Q', 'F', 'S', 'H'});
	init[7] = vector<char>({'W', 'L', 'F'});
	init[8] = vector<char>({'S', 'V', 'F', 'M', 'R'});
	return init;
}

void printer(vector<vector<char>> vvc) {
	for (auto vc : vvc) {
		string s = "";
		for (auto c : vc) {
			s += c;
			s += ", ";
		}
		cout << left << setw(30) << s << ":" << vc.size() << endl;
	}
	cout << "--" << endl;
}

void grabData(int& n1, int& n2, int& n3) {
	string s_move;
	string s_n1;
	string s_from;
	string s_n2;
	string s_to;
	string s_n3;
	getline(cin, s_move, ' ');
	getline(cin, s_n1, ' ');
	getline(cin, s_from, ' ');
	getline(cin, s_n2, ' ');
	getline(cin, s_to, ' ');
	getline(cin, s_n3);
	n1 = stoi(s_n1);
	n2 = stoi(s_n2);
	n3 = stoi(s_n3);
}

int main() {
	auto vvc = init();
	printer(vvc);
	int n1;
	int n2;
	int n3;
	int q = 502;
	while (q--) {
		grabData(n1, n2, n3);
		printf("%d, %d, %d\n", n1, n2, n3);

		// do movement
		auto source_vc = vvc[n2 - 1];
		auto& dst_vc = vvc[n3 - 1];
		auto move_count = n2;

		vector<char> source_retained;
		vector<char> source_extracted;
		for (int i = 0; i < source_vc.size() - n1; i++) {
			source_retained.push_back(source_vc[i]);
		}
		vvc[n2 - 1] = source_retained;
		for (int i = source_vc.size() - n1; i < source_vc.size(); i++) {
			source_extracted.push_back(source_vc[i]);
		}
		// uncomment to handle part 1
		// reverse(source_extracted.begin(), source_extracted.end());
		dst_vc.insert(dst_vc.end(), source_extracted.begin(),
		              source_extracted.end());
		printer(vvc);
		cout << q << endl;
	}

	printer(vvc);

	return 1;
}
