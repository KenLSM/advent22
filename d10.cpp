#include <bits/stdc++.h>

using namespace std;

int programX = 1;
char ppx[240];

int ans1 = 0;

void draw(int& pc, int& px) {
	int _pc = (pc % 40) - px;
	if (_pc >= 0 && _pc <= 2) {
		ppx[pc] = '#';
	}
}
void incrementCycle(int& pc) {
	draw(pc, programX);
	if (pc == 20) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	if (pc == 60) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	if (pc == 100) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	if (pc == 140) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	if (pc == 180) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	if (pc == 220) {
		printf("Cycle: %d, X: %d\n", pc, programX);
		ans1 += pc * programX;
	}
	pc++;
}

void printscreen() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 40; j++) {
			printf("%c", ppx[i * 40 + j]);
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int programCycle = 1;

	for (int i = 0; i < 240; i++) {
		ppx[i] = '.';
	}
	string c;
	while (true) {
		cin >> c;
		if (c == "noop") {
			incrementCycle(programCycle);
		} else {
			int tempV = 0;
			cin >> tempV;

			incrementCycle(programCycle);
			incrementCycle(programCycle);
			programX += tempV;
		}
		if (cin.eof()) {
			break;
		}
	}
	printf("Ans1: %d\n", ans1);
	printscreen();
	return 1;
}