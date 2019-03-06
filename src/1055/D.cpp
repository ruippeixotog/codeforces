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

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

string w[MAXN], wt[MAXN];

string replace(string str, string& from, string& to) {
  int idx = (int) str.find(from);
  if(idx >= 0) {
    return str.replace(idx, from.size(), to);
  }
  return str;
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> wt[i];
  }
  vector<string> w2, wt2;
  for(int i = 0; i < n; i++) {
    if(w[i] != wt[i]) {
      w2.push_back(w[i]);
      wt2.push_back(wt[i]);
    }
  }

  int lOut = 0, lIn = lOut, rOut = (int) w2[0].length() - 1, rIn = rOut;
  while(w2[0][lIn] == wt2[0][lIn]) lIn++;
  while(w2[0][rIn] == wt2[0][rIn]) rIn--;

  queue<string> q, qt;
  for(int i = 0; i <= lIn; i++) {
    for(int j = w2[0].length() - 1; j >= rIn; j--) {
//      fprintf(stderr, "possible: %s -> %s\n",
//        w2[0].substr(i, j - i + 1).c_str(), wt2[0].substr(i, j - i + 1).c_str());

      q.push(w2[0].substr(i, j - i + 1));
      qt.push(wt2[0].substr(i, j - i + 1));
    }
  }

  cerr << q.size() << endl;

  bool possible = false;
  while(!q.empty() && !possible) {
    possible = true;
    for(int i = 1; i < w2.size() && !q.empty(); i++) {
//      fprintf(stderr, "test: replace(%s, %s, %s) != %s\n", w2[i].c_str(), q.front().c_str(), qt.front().c_str(), wt2[i].c_str());
      if(replace(w2[i], q.front(), qt.front()) != wt2[i]) {
//        fprintf(stderr, "test failed\n");
        possible = false;
        q.pop(); qt.pop();
        i--;
      }
    }
  }

  if(q.empty()) printf("NO\n");
  else {
    printf("YES\n");
    cout << q.front() << endl;
    cout << qt.front() << endl;
  }
  return 0;
}
