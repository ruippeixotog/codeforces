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
  int n, k; scanf("%d %d\n", &n, &k);

  int maxT = 4 * 60 - k;
  int i = 0, t = 0;
  while(i < n && t + 5 * (i + 1) <= maxT) {
    t += 5 * (i + 1);
    i++;
  }

  printf("%d\n", i);
  return 0;
}
