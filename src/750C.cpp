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

int c[MAXN], d[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &c[i], &d[i]);

  int maxStart = INF, curr = INF;
  for(int i = 0; i < n; i++) {
    if(d[i] == 2 && curr >= 1900) {
      int adjust = curr - 1900 + 1;
      curr -= adjust;
      maxStart -= adjust;
    }
    curr += c[i];
  }

  curr = maxStart;
  bool valid = true;
  for(int i = 0; i < n; i++) {
    if(d[i] == 1 && curr < 1900) { valid = false; break; }
    curr += c[i];
  }

  if(!valid) printf("Impossible\n");
  else if(maxStart == INF) printf("Infinity\n");
  else printf("%d\n", curr);
  return 0;
}
