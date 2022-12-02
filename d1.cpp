#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector<int> > vvi;
  vector<int>* cur = new vector<int>();
  string s;
  while (!cin.eof()) {
    getline(cin, s);
    cout << "|" << s << "|" << endl;
    if(s == "") {
      cout << "New Vector" << endl;
      vvi.push_back(*cur);
      cur = new vector<int>();
      continue;
    }
    auto i = stoi(s);
    cur->push_back(i);
  }

  auto max_i = 0;
  priority_queue<int, vector<int>, less<int> > pq;
  for(auto v: vvi) {
    auto cur_i = 0; 
    for(auto i: v) {
      cur_i += i;
    }
    max_i = max(max_i, cur_i);
    pq.push(cur_i);
  }
  cout << max_i << endl;
  
  for(int i = 1; i <= 3; i++) {
    auto top = pq.top();
    pq.pop();
    printf("#%d: %d\n", i, top);
  }
}