#include <bits/stdc++.h>

using namespace std;

unordered_set<string> seen;
pair<int, int> head;
pair<int, int> tail;

int calManhattenDis() {
	return abs(head.first - tail.first) + abs(head.second - tail.second);
}

void moveHead(char direction) {
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

void moveTail() {
	int matDis = calManhattenDis();
	if (matDis <= 1) {
		// tail doesn't have to move
		return;
	}
	printf("Need to move tail\n");

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
void recordTail() {
	seen.insert(toHash(tail));
}

void printSeen() {
	for (auto s : seen) {
		printf("%s\n", s.c_str());
	}
	printf("-----\n");
}
int main() {
	head = pair<int, int>(0, 0);
	tail = pair<int, int>(0, 0);
	while (true) {
		char direction;
		int steps;
		cin >> direction >> steps;
		while (steps--) {
			moveHead(direction);
			moveTail();
			recordTail();
		}

		if (cin.eof()) {
			break;
		}
	}
	printSeen();
	printf("Ans1: %ld\n", seen.size());
	return 1;
}