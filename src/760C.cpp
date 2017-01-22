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

int p[MAXN];

bool visited[MAXN];

void go(int i) {
  if(!visited[i]) {
    visited[i] = true;
    go(p[i] - 1);
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  int bSum = 0;
  for(int i = 0; i < n; i++) {
    int b; scanf("%d", &b);
    bSum += b;
  }

  int loopCnt = 0;
  for(int i = 0; i < n; i++) {
    if(!visited[i]) { loopCnt++; go(i); }
  }

  int res = (loopCnt == 1 ? 0 : loopCnt) + (bSum % 2 == 0);
  printf("%d\n", res);
  return 0;
}
