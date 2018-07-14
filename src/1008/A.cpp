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

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool isValid(string& s) {
  bool anyLetter = true;
  for(int i = 0; i < s.size(); i++) {
    if(!anyLetter && !vowels.count(s[i])) {
      return false;
    }
    anyLetter = vowels.count(s[i]) || s[i] == 'n';
  }
  return anyLetter;
}

int main() {
  string s; cin >> s;
  printf(isValid(s) ? "YES\n" : "NO\n");
  return 0;
}
