#include <bits/stdc++.h>
#define UNCOVERED_DIS 99999

using namespace std;

vector<vector<int>> source_map;
vector<vector<int>> dis_map;

void flood(pair<int, int> startingPos) {
	queue<pair<int, int>> q;
	q.push(startingPos);
	dis_map[startingPos.first][startingPos.second] = 1;
	while (!q.empty()) {
		auto x = q.front().first, y = q.front().second;
		q.pop();

		if (x > 0 && dis_map[x - 1][y] == UNCOVERED_DIS
		    && source_map[x - 1][y] - source_map[x][y] <= 1) {
			q.push(pair<int, int>(x - 1, y));
			dis_map[x - 1][y] = min(dis_map[x][y] + 1, dis_map[x - 1][y]);
		}

		int max_x = source_map.size() - 1;
		if (x < max_x && dis_map[x + 1][y] == UNCOVERED_DIS
		    && source_map[x + 1][y] - source_map[x][y] <= 1) {
			q.push(pair<int, int>(x + 1, y));
			dis_map[x + 1][y] = min(dis_map[x][y] + 1, dis_map[x + 1][y]);
		}

		if (y > 0 && dis_map[x][y - 1] == UNCOVERED_DIS
		    && source_map[x][y - 1] - source_map[x][y] <= 1) {
			q.push(pair<int, int>(x, y - 1));
			dis_map[x][y - 1] = min(dis_map[x][y] + 1, dis_map[x][y - 1]);
		}

		int max_y = source_map[0].size() - 1;
		if (y < max_y && dis_map[x][y + 1] == UNCOVERED_DIS
		    && source_map[x][y + 1] - source_map[x][y] <= 1) {
			q.push(pair<int, int>(x, y + 1));
			dis_map[x][y + 1] = min(dis_map[x][y] + 1, dis_map[x][y + 1]);
		}
	}
}

void print(vector<vector<int>> _map) {
	for (auto a : _map) {
		for (auto b : a) {
			printf("%d,", b);
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void resetDisMap() {
	for (auto& yList : dis_map) {
		for (auto& point : yList) {
			point = UNCOVERED_DIS;
		}
	}
}
int main() {
	string s;
	while (true) {
		cin >> s;
		vector<int> source_line, dis_line;
		for (char c : s) {
			source_line.push_back(c);
			dis_line.push_back(UNCOVERED_DIS);
		}
		source_map.push_back(source_line);
		dis_map.push_back(dis_line);

		if (cin.eof()) {
			break;
		}
	}

	// find E
	pair<int, int> E;
	for (int i = 0; i < source_map.size(); i++) {
		for (int j = 0; j < source_map[0].size(); j++) {
			if (source_map[i][j] == 'E') {
				E = pair<int, int>(i, j);
				// source_map[i][j] = 'z';
				break;
			}
		}
	}

	vector<pair<int, int>> startPosList;
	for (int i = 0; i < source_map.size(); i++) {
		for (int j = 0; j < source_map[0].size(); j++) {
			if (source_map[i][j] == 'a') {
				startPosList.push_back(pair<int, int>(i, j));
			}
		}
	}
	printf("Valid Starting Positions: %d\n", startPosList.size());
	int minVal = UNCOVERED_DIS;
	pair<int, int> minPos;
	for (auto pos : startPosList) {
		resetDisMap();
		flood(pos);

		if (minVal > dis_map[E.first][E.second]) {
			minVal = dis_map[E.first][E.second];
			minPos = pos;
			printf("(%d, %d), %d, %c\n",
			       E.first,
			       E.second,
			       dis_map[E.first][E.second],
			       source_map[E.first][E.second]);

			printf("(%d, %d), %d, %c\n",
			       E.first + 1,
			       E.second,
			       dis_map[E.first + 1][E.second],
			       source_map[E.first + 1][E.second]);

			printf("(%d, %d), %d, %c\n",
			       E.first - 1,
			       E.second,
			       dis_map[E.first - 1][E.second],
			       source_map[E.first - 1][E.second]);

			printf("(%d, %d), %d, %c\n",
			       E.first,
			       E.second + 1,
			       dis_map[E.first][E.second + 1],
			       source_map[E.first][E.second + 1]);

			printf("(%d, %d), %d, %c\n",
			       E.first,
			       E.second - 1,
			       dis_map[E.first][E.second - 1],
			       source_map[E.first][E.second - 1]);
			printf("---\n");
		}
	}
	// print(source_map);
	// print(dis_map);
	// print(source_map);
	// print(dis_map);

	cout << minVal << endl;
	cout << minPos.first << " " << minPos.second << endl;
	for (auto pos : startPosList) {
		// printf("Pos: (%d, %d)\n", pos.first, pos.second);
	}
	return 1;
}
