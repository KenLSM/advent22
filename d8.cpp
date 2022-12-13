#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vvi;
void readInput() {
	string l;
	while (true) {
		getline(cin, l);
		vector<int> vi;
		for (char c : l) {
			vi.push_back(c - '0');
		}
		vvi.push_back(vi);
		if (cin.eof()) {
			break;
		}
	}
}

void print() {
	for (auto vi : vvi) {
		for (auto i : vi) {
			printf("%d ", i);
		}
		cout << endl;
	}
	cout << endl;

	printf("%d x %d\n", vvi.size(), vvi[0].size());
}

bool traceTop(int i, int j, int height) {
	// cout << "traceTop" << endl;
	while (--i >= 0) {
		if (vvi[i][j] >= height) {
			return false;
		}
	}
	return true;
}

bool traceBtm(int i, int j, int height) {
	// cout << "traceBtm" << endl;
	int max_i = vvi.size() - 1;
	while (++i <= max_i) {
		if (vvi[i][j] >= height) {
			return false;
		}
	}
	return true;
}

bool traceLeft(int i, int j, int height) {
	// cout << "traceLeft" << endl;
	while (--j >= 0) {
		if (vvi[i][j] >= height) {
			return false;
		}
	}
	return true;
}

bool traceRight(int i, int j, int height) {
	// cout << "traceRight" << endl;
	int max_j = vvi[0].size() - 1;
	while (++j <= max_j) {
		if (vvi[i][j] >= height) {
			return false;
		}
	}
	return true;
}

int countTop(int i, int j, int height) {
	int count = 0;
	while (--i >= 0) {
		count++;
		if (vvi[i][j] >= height) {
			break;
		}
	}
	printf("countTop %d\n", count);
	return count;
}

int countBtm(int i, int j, int height) {
	int count = 0;
	int max_i = vvi.size() - 1;
	while (++i <= max_i) {
		count++;
		if (vvi[i][j] >= height) {
			break;
		}
	}
	printf("countBtm %d\n", count);
	return count;
}

int countLeft(int i, int j, int height) {
	int count = 0;
	while (--j >= 0) {
		count++;
		if (vvi[i][j] >= height) {
			break;
		}
	}
	printf("countLeft %d\n", count);
	return count;
}

int countRight(int i, int j, int height) {
	int max_j = vvi[0].size() - 1;
	int count = 0;
	while (++j <= max_j) {
		count++;
		if (vvi[i][j] >= height) {
			break;
		}
	}
	printf("countRight %d\n", count);
	return count;
}

int main() {
	readInput();
	print();

	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < vvi.size(); i++) {
		for (int j = 0; j < vvi[0].size(); j++) {
			if (traceTop(i, j, vvi[i][j]) || traceBtm(i, j, vvi[i][j])
			    || traceLeft(i, j, vvi[i][j]) || traceRight(i, j, vvi[i][j])) {
				printf("(%d,%d), %d\n", i, j, vvi[i][j]);
				ans1++;
			}

			int viewDis = countTop(i, j, vvi[i][j]) * countBtm(i, j, vvi[i][j])
			              * countLeft(i, j, vvi[i][j])
			              * countRight(i, j, vvi[i][j]);
			ans2 = max(ans2, viewDis);
			printf("viewDis: (%d,%d), H: %d, %d\n", i, j, vvi[i][j], viewDis);
		}
	}
	printf("Ans1: %d\n", ans1);
	printf("Ans2: %d\n", ans2);
	return 1;
}