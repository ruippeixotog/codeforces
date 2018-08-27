#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

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
  if(!buy.empty()) {
    if(p == buy.top()) {
      buy.pop();
      for(int p0 : middle) {
        sell.push(p0);
      }
      middle.clear();
      return;
    }
    if(p < buy.top()) {
      cnt = 0;
      return;
    }
  }
  if(!sell.empty()) {
    if(p == sell.top()) {
      sell.pop();
      for(int p0 : middle) {
        buy.push(p0);
      }
      middle.clear();
      return;
    }
    if(p > sell.top()) {
      cnt = 0;
      return;
    }
  }
  for(int p0 : middle) {
    if(p0 < p) buy.push(p0);
    else if(p0 > p) sell.push(p0);
  }
  middle.clear();
  cnt = (int) mmul(cnt, 2);
}

int main() {
  int n; scanf("%d\n", &n);

  for(int i = 0; i < n; i++) {
    int p;
    if(scanf("ADD %d\n", &p) == 1) {
      add(p);
    } else if(scanf("CCEPT %d\n", &p) == 1) {
      accept(p);
    }
  }
  cnt = (int) mmul(cnt, (int) middle.size() + 1);
  printf("%d\n", cnt);
  return 0;
}
