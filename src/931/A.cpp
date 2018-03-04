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

int asum(int n) {
  return n * (1 + n) / 2;
}

int main() {
  int a, b; scanf("%d %d\n", &a, &b);
  int dist = abs(a - b);
  int res = asum(dist / 2) + asum(dist - dist / 2);
  printf("%d\n", res);
  return 0;
}
