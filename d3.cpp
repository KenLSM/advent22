#include <bits/stdc++.h>
using namespace std;

int ascii2i(char c) {
  if (c <= 'z' && c >= 'a') {
    return c - 'a';
  }
  return c - 'A' + 26;
}

int main2(vector<string> &part2) {
  int ans2 = 0;
  for (int i = 0; i < part2.size(); i += 3) {
    string input1 = part2[i];
    string input2 = part2[i + 1];
    string input3 = part2[i + 2];

    // into a map
    int arr1[52], arr2[52], arr3[52];
    for (int i = 0; i < 52; i++) {
      arr1[i] = 0;
      arr2[i] = 0;
      arr3[i] = 0;
    }

    for (int i = 0; i < input1.length(); i++) {
      int c = ascii2i(input1[i]);
      arr1[c] += 1;
    }
    for (int i = 0; i < input2.length(); i++) {
      int c = ascii2i(input2[i]);
      arr2[c] += 1;
    }
    for (int i = 0; i < input3.length(); i++) {
      int c = ascii2i(input3[i]);
      arr3[c] += 1;
    }

    // match detection
    for (int i = 0; i < 52; i++) {
      if (arr1[i] != 0 && arr2[i] != 0 && arr3[i] != 0) {
        ans2 += i + 1;
      }
    }
  }
  printf("Ans2: %d\n", ans2);
  return 1;
}

int main() {
  int ans1 = 0;
  vector<string> part2;
  while (true) {
    string input0, input1, input2;
    getline(cin, input0);
    part2.push_back(input0);

    input1 = input0.substr(0, input0.length() / 2);
    input2 = input0.substr(input0.length() / 2, input0.length() / 2);
    cout << input1 << endl;
    cout << input2 << endl;
    cout << endl;

    // into a map
    int arr1[52], arr2[52];
    for (int i = 0; i < 52; i++) {
      arr1[i] = 0;
      arr2[i] = 0;
    }

    for (int i = 0; i < input1.length(); i++) {
      int c = ascii2i(input1[i]);
      arr1[c] += 1;
    }
    for (int i = 0; i < input2.length(); i++) {
      int c = ascii2i(input2[i]);
      arr2[c] += 1;
    }

    // match detection
    for (int i = 0; i < 52; i++) {
      if (arr1[i] != 0 && arr2[i] != 0) {
        ans1 += i + 1;
        cout << (i + 1) << endl;
      }
    }

    if (cin.eof()) {
      break;
    }
  }
  printf("Ans1: %d\n", ans1);

  main2(part2);
  return 1;
}
