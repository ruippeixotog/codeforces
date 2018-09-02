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
  int n, s; scanf("%d %d\n", &n, &s);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);

  ll ops = 0;
  if(a[n / 2] > s) {
    for(int i = n / 2; i >= 0 && a[i] > s; i--) {
      ops += a[i] - s;
    }
  } else {
    for(int i = n / 2; i < n && a[i] < s; i++) {
      ops += s - a[i];
    }
  }
  printf("%lld\n", ops);
  return 0;
}
