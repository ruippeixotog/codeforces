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
  int y, b, r; scanf("%d %d %d\n", &y, &b, &r);

  int best;
  for(best = 98; best >= 1; best--) {
    if(y >= best && b >= best + 1 && r >= best + 2) {
      break;
    }
  }
  printf("%d\n", (best + 1) * 3);
  return 0;
}
