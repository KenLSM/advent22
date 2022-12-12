#include <bits/stdc++.h>
#define LIMIT 100000
#define TARGET 30000000
#define SPACE 70000000

using namespace std;

struct Node {
	string _name;
	string _type; // file|dir
	int _size;    // >=0
	Node* parent;
	vector<Node*> children;
	Node(string n, string t, int s, Node* p)
	    : _name(n), _type(t), _size(s), parent(p) {
	}
};

int ans = 0;
vector<long> dirSum;

int sumOfChild(Node* _h) {
	auto h = *_h;
	int sum = h._size;
	auto c = h.children;
	cout << "In: " << h._name << endl;
	bool exceeded = sum > LIMIT;
	for (auto n : c) {
		int s = sumOfChild(n);
		if (s > LIMIT) {
			exceeded = true;
			continue;
		}
		sum += s;
		if (sum > LIMIT) {
			exceeded = true;
			continue;
		}
	}
	if (!exceeded && h._type == "dir") {
		cout << "SUM: " << sum << endl;
		ans += sum;
	}
	return exceeded ? LIMIT + 1 : sum;
}

long sumOfChild2(Node* _h) {
	auto h = *_h;
	long sum = h._size;
	auto c = h.children;
	for (auto n : c) {
		long s = sumOfChild2(n);
		sum += s;
	}
	dirSum.push_back(sum);
	return sum;
}

Node* cdTo(Node* _h, string target) {
	auto h = *_h;
	auto c = h.children;
	for (auto n : c) {
		if (n->_name == target) {
			return n;
		}
	}

	cout << "NO CHILD" << endl;
	return _h;
}

int main() {
	Node* ROOT = new Node(string("ROOT"), "dir", 0, NULL);
	Node* head = ROOT;
	while (true) {
		string c;
		cin >> c;
		if (c == "$") {
			cin >> c;
			if (c == "cd") {
				cin >> c;
				if (c == "/") {
					cout << "START" << endl;
					continue;
				}
				if (c == "..") {
					head = head->parent;
					continue;
				}

				head = cdTo(head, c);
				cout << "CD: to " << c << endl;
				continue;
			}
			if (c == "ls") {
				cout << "CMD: $ ls " << endl;
				continue;
			}
			cout << "UNKNOWN: " << c << endl;
			continue;
		}
		if (c == "dir") {
			string name;
			cin >> name;
			Node* n = new Node(name, "dir", 0, head);
			head->children.push_back(n);
			printf("DIR %s Created\n", name.c_str());
			continue;
		}
		string name;
		int size = stoi(c);
		cin >> name;
		Node* n = new Node(name, "file", size, head);
		head->children.push_back(n);
		printf("FILE %s Created %d\n", name.c_str(), size);

		if (cin.eof()) {
			break;
		}
	}

	int sum = sumOfChild(ROOT);
	cout << sum << endl;
	printf("Ans: %d\n", ans);

	sumOfChild2(ROOT);

	long ans2 = SPACE;
	long largest = 0;
	for (auto i : dirSum) {
		largest = max(largest, i);
	}
	long emptySpace = SPACE - largest;
	long neededSpace = TARGET - emptySpace;

	for (auto i : dirSum) {
		printf("%ld, ", i);
		if (i > neededSpace) {
			ans2 = min(ans2, i);
		}
	}
	cout << endl;
	printf("Largest: %ld\n", largest);
	printf("Ans2: %ld\n", ans2);
	return 1;
}