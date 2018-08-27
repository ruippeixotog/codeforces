#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }

priority_queue<int> buy;
priority_queue<int, vector<int>, greater<int>> sell;
vector<int> middle;

int cnt = 1;

void add(int p) {
  if(!buy.empty() && p < buy.top()) {
    buy.push(p);
  } else if(!sell.empty() && p > sell.top()) {
    sell.push(p);
  } else {
    middle.push_back(p);
  }
}

void accept(int p) {
  if(!buy.empty() && p < buy.top()) { cnt = 0; return; }
  if(!sell.empty() && p > sell.top()) { cnt = 0; return; }

  for(int p0 : middle) {
    if(p0 < p) buy.push(p0);
    else if(p0 > p) sell.push(p0);
  }
  middle.clear();

  if(!buy.empty() && p == buy.top()) buy.pop();
  else if(!sell.empty() && p == sell.top()) sell.pop();
  else cnt = (int) mmul(cnt, 2);
}

int main() {
  int n; cin >> n;

  string action; int p;
  for(int i = 0; i < n; i++) {
    cin >> action >> p;
    if(action == "ADD") add(p);
    else accept(p);
  }
  cnt = (int) mmul(cnt, (int) middle.size() + 1);
  cout << cnt << endl;
  return 0;
}
