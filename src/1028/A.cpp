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

#define MAXN 115
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

char s[MAXN][MAXN];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &s[i][j]);
    }
    scanf("\n");
  }

  int r = -1, c = -1;
  for(int i = 0; i < n && r < 0; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'W') continue;
      for(r = i + 1; r < n && s[r][j] == 'B'; r++);
      r = (i + r) / 2;
      for(c = j + 1; c < m && s[i][c] == 'B'; c++);
      c = (j + c) / 2;
      break;
    }
  }
  printf("%d %d\n", r + 1, c + 1);
  return 0;
}
