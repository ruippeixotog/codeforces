#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    set<int> revIdx[26];
    for(int i = 0; i < s.length(); i++) {
      revIdx[s[i] - 'a'].insert(i);
    }

    int ti = 0, si = 0;
    int cnt = 0;
    while(ti < t.length()) {
      auto& set = revIdx[t[ti] - 'a'];
      auto it = set.lower_bound(si);
      if(it == set.end()) {
        if(si == 0) { cnt = -1; break; }
        else si = 0;
      } else {
        if(si == 0) cnt++;
        si = *it + 1;
        ti++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
