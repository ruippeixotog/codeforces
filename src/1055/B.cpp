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

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

int main() {
  int n, m, l; scanf("%d %d %d\n", &n, &m, &l);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int groups = 0;
  if(a[0] > l) groups++;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] <= l && a[i] > l)
      groups++;
  }
  cerr << "g: " << groups << endl;

  for(int i = 0; i < m; i++) {
    int ti; scanf("%d", &ti);
    if(ti == 0) {
      printf("%d\n", groups);
    } else {
      int p, d; scanf("%d %d", &p, &d);
      if(a[--p] > l) continue;
      a[p] += d;
      if(a[p] > l) {
        bool lGroup = p > 0 && a[p - 1] > l;
        bool rGroup = p < n - 1 && a[p + 1] > l;
        if(!lGroup && !rGroup) groups++;
        if(lGroup && rGroup) groups--;
      }
    }
  }
  return 0;
}
