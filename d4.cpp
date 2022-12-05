#include <bits/stdc++.h>

using namespace std;
bool check1(int a1, int a2, int b1, int b2) {
  if (a1 <= b1 && a2 >= b2) {
    return true;
  }
  if (b1 <= a1 && b2 >= a2) {
    return true;
  }
  return false;
}

bool check2(int a1, int a2, int b1, int b2) {
  if (check1(a1, a2, b1, b2)) {
    return true;
  }
  if (b1 <= a2 && a1 <= b2) {
    return true;
  }
  if (a1 <= b2 && b1 <= a2) {
    return true;
  }
  return false;
}
int main() {
  int ans1 = 0, ans2 = 0;
  while (true) {
    string line;
    cin >> line;

    stringstream ss(line);

    int a1, a2, b1, b2;
    char comma;
    ss >> a1 >> a2 >> comma >> b1 >> b2;
    a2 *= -1;
    b2 *= -1;

    cout << a1 << " | " << a2;
    cout << "\t";
    cout << b1 << " | " << b2 << endl;
    if (check1(a1, a2, b1, b2)) {
      ans1++;
    }
    if (check2(a1, a2, b1, b2)) {
      ans2++;
    }
    if (cin.eof()) {
      break;
    }
  }
  printf("Ans1: %d\n", ans1);
  printf("Ans2: %d\n", ans2);
  return 1;
}