#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

unordered_set<string> seen;
unordered_set<string> seen2;
vector<pii> knots;
// pair<int, int> head;
// pair<int, int> tail;

int calManhattenDis(pii &head, pii &tail) {
	return abs(head.first - tail.first) + abs(head.second - tail.second);
}

void moveHead(pii &head, char direction) {
	switch (direction) {
	case 'L': {
		head.first--;
		break;
	}
	case 'R': {
		head.first++;
		break;
	}
	case 'U': {
		head.second--;
		break;
	}
	case 'D': {
		head.second++;
		break;
	}
	}
}

// void moveTail() {}
void moveTail(pii &head, pii &tail) {
	int matDis = calManhattenDis(head, tail);
	if (matDis <= 1) {
		// tail doesn't have to move
		return;
	}
	// printf("Need to move tail\n");

	if (matDis == 2) {
		int dir_lr = head.first - tail.first;
		if (abs(dir_lr) == 2) {
			if (dir_lr < 0) {
				tail.first--;
			} else {
				tail.first++;
			}
			return;
		}
		int dir_td = head.second - tail.second;
		if (abs(dir_td) == 2) {
			if (dir_td < 0) {
				tail.second--;
			} else {
				tail.second++;
			}
			return;
		}
		// tail and head are now touchingly-diagonal
		return;
	}
	// matDis is now 3 -> move hori + verti
	int dir_lr = head.first - tail.first;
	if (dir_lr < 0) {
		tail.first--;
	} else {
		tail.first++;
	}

	int dir_td = head.second - tail.second;
	if (dir_td < 0) {
		tail.second--;
	} else {
		tail.second++;
	}
}

string toHash(pair<int, int> p) {
	char s[50];
	sprintf(s, "(%d,%d)", p.first, p.second);
	return s;
}
void recordTail(pii &tail) {
	seen.insert(toHash(tail));
}
void recordTail2(pii &tail) {
	seen2.insert(toHash(tail));
}

void printSeen() {
	for (auto s : seen) {
		printf("%s\n", s.c_str());
	}
	printf("-----\n");
}

int main() {
	for (int i = 0; i < 10; i++) {
		knots.push_back(pii(0, 0));
	}
	// head = pair<int, int>(0, 0);
	// tail = pair<int, int>(0, 0);
	while (true) {
		char direction;
		int steps;
		cin >> direction >> steps;
		while (steps--) {
			moveHead(knots[0], direction);
			for (int i = 0; i < 9; i++) {
				moveTail(knots[i], knots[i + 1]);
			}
			// moveTail(knots[0], knots[1]);
			recordTail(knots[1]);
			recordTail2(knots[9]);
		}

		if (cin.eof()) {
			break;
		}
	}
	printSeen();
	printf("Ans1: %ld\n", seen.size());
	printf("Ans2: %ld\n", seen2.size());
	return 1;
}