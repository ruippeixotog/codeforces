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
  int n, h, a, b, k; scanf("%d %d %d %d %d\n", &n, &h, &a, &b, &k);
  while(k--) {
    int ta, fa, tb, fb; scanf("%d %d %d %d\n", &ta, &fa, &tb, &fb);

    int cost = 0;
    if(ta != tb) {
      cost += abs(ta - tb);
      if(fa < a) {
        cost += a - fa;
        fa = a;
      } else if(fa > b) {
        cost += fa - b;
        fa = b;
      }
    }
    cost += abs(fa - fb);
    printf("%d\n", cost);
  }
  return 0;
}
