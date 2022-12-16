#include <bits/stdc++.h>
#define MODULO 9699690
// #define MODULO 96577

using namespace std;

class Monki {
	long operation(long &itemWorryLevel) {
		long ll = itemWorryLevel;
		if (operationFormula == 0) {
			itemWorryLevel = ll * ll;
			// printf("itemWorryLevel: %ld = %ld * %ld\n", itemWorryLevel, ll,
			// ll); itemWorryLevel /= 3;
			itemWorryLevel %= MODULO;
			// printf("itemWorryLevel, Post: %ld\n", itemWorryLevel);
			return itemWorryLevel;
		}
		if (operationFormula < 0) {
			itemWorryLevel = ll + abs(operationFormula);
			// printf("itemWorryLevel: %ld = %ld + %ld\n", itemWorryLevel,
			//    abs(operationFormula), ll);
			// itemWorryLevel /= 3;
			itemWorryLevel %= MODULO;
			// printf("itemWorryLevel, Post: %ld\n", itemWorryLevel);
			return itemWorryLevel;
		}
		itemWorryLevel = ll * operationFormula;
		// printf("itemWorryLevel: %ld = %ld * %ld\n", itemWorryLevel,
		//    abs(operationFormula), ll);
		// itemWorryLevel /= 3;
		itemWorryLevel %= MODULO;
		// printf("itemWorryLevel, Post: %ld\n", itemWorryLevel);
		return itemWorryLevel;
	};

public:
	queue<long> items;
	long operationFormula;
	long test_divisible;
	long test_true_monki;
	long test_false_monki;
	long inspectCount;
	Monki(vector<long> &_startItems, long _operationFormula,
	      long _test_divisible, long _test_true_monki, long _test_false_monki) {
		for (auto i : _startItems) {
			items.push(i);
		}
		operationFormula = _operationFormula;
		test_divisible = _test_divisible;
		test_true_monki = _test_true_monki;
		test_false_monki = _test_false_monki;
		inspectCount = 0;
	}

	long test(long &itemWorryLevel) {
		inspectCount++;
		if (operation(itemWorryLevel) % test_divisible == 0) {
			return test_true_monki;
		}
		return test_false_monki;
	}
};

vector<Monki> initTest() {
	vector<Monki> mArr;
	vector<long> v0{79, 98};
	Monki m0(v0, 19, 23, 2, 3);
	mArr.push_back(m0);

	vector<long> v1{54, 65, 75, 74};
	Monki m1(v1, -6, 19, 2, 0);
	mArr.push_back(m1);

	vector<long> v2{79, 60, 97};
	Monki m2(v2, 0, 13, 1, 3);
	mArr.push_back(m2);

	vector<long> v3{74};
	Monki m3(v3, -3, 17, 0, 1);
	mArr.push_back(m3);

	return mArr;
}

vector<Monki> init() {
	vector<Monki> mArr;
	vector<long> v0{98, 89, 52};
	Monki m0(v0, 2, 5, 6, 1);
	mArr.push_back(m0);

	vector<long> v1{57, 95, 80, 92, 57, 78};
	Monki m1(v1, 13, 2, 2, 6);
	mArr.push_back(m1);

	vector<long> v2{82, 74, 97, 75, 51, 92, 83};
	Monki m2(v2, -5, 19, 7, 5);
	mArr.push_back(m2);

	vector<long> v3{97, 88, 51, 68, 76};
	Monki m3(v3, -6, 7, 0, 4);
	mArr.push_back(m3);

	vector<long> v4{63};
	Monki m4(v4, -1, 17, 0, 1);
	mArr.push_back(m4);

	vector<long> v5{94, 91, 51, 63};
	Monki m5(v5, -4, 13, 4, 3);
	mArr.push_back(m5);

	vector<long> v6{61, 54, 94, 71, 74, 68, 98, 83};
	Monki m6(v6, -2, 3, 2, 7);
	mArr.push_back(m6);

	vector<long> v7{90, 56};
	Monki m7(v7, 0, 11, 3, 5);
	mArr.push_back(m7);

	return mArr;
}

void printItems(queue<long> items) {
	auto _i = queue<long>(items);
	while (!_i.empty()) {
		auto ii = _i.front();
		_i.pop();
		printf("%ld, ", ii);
	}
	printf("\n");
}
void gameLoop(vector<Monki> &mk) {
	// long count = 20;
	long count = 10000;
	while (count--) {
		cout << "Game Loop: " << count << endl;
		for (long mki = 0; mki < mk.size(); mki++) {
			Monki &m = mk[mki];
			while (!m.items.empty()) {
				auto i = m.items.front();
				m.items.pop();
				long targetMonki = m.test(i);
				// printf("Target %ld, with item: %ld\n", targetMonki, i);
				mk[targetMonki].items.push(i);
			}
		}
		// for (long mki = 0; mki < mk.size(); mki++) {
		// 	Monki &m = mk[mki];
		// 	cout << "Monki: " << mki << ": ";
		// 	printItems(m.items);
		// }
	}
}
int main() {
	// auto mArr = initTest();
	auto mArr = init();
	gameLoop(mArr);

	for (auto m : mArr) {
		printf("%ld, ", m.inspectCount);
	}
	return 1;
}