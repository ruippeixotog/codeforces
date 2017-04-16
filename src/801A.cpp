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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int main() {
  string str; cin >> str;

  int best = 0;
  for(int i = 1; i < str.size(); i++) {
    if(str[i - 1] == 'V' && str[i] == 'K') best++;
  }

  for(int i = 0; i < str.size(); i++) {
    str[i] = str[i] == 'V' ? 'K' : 'V';

    int cnt = 0;
    for(int j = 1; j < str.size(); j++) {
      if(str[j - 1] == 'V' && str[j] == 'K') cnt++;
    }
    best = max(best, cnt);
    str[i] = str[i] == 'V' ? 'K' : 'V';
  }
  printf("%d\n", best);
  return 0;
}
