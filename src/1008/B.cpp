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

int w[MAXN], h[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &w[i], &h[i]);

  bool canOrder = true;
  int maxHeight = INF;
  for(int i = 0; i < n; i++) {
    if(max(w[i], h[i]) <= maxHeight) {
      maxHeight = max(w[i], h[i]);
    } else if(min(w[i], h[i]) <= maxHeight) {
      maxHeight = min(w[i], h[i]);
    } else {
      canOrder = false;
      break;
    }
  }
  printf(canOrder ? "YES\n" : "NO\n");
  return 0;
}
