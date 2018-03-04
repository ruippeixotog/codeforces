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

int main() {
  int n, a, b; scanf("%d %d %d\n", &n, &a, &b);

  int round = 1;
  for(; n > 2; n /= 2, round++) {
    if((a + 1) / 2 == (b + 1) / 2) break;
    a = (a + 1) / 2; b = (b + 1) / 2;
  }

  if(n == 2) printf("Final!\n");
  else printf("%d\n", round);
  return 0;
}
