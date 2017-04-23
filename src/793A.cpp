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

int n, k, a[MAXN];

ll calc() {
  int mod = a[0] % k, minPrice = a[0];
  for(int i = 1; i < n; i++) {
    if(a[i] % k != mod) return -1;
    minPrice = min(minPrice, a[i]);
  }
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += (a[i] - minPrice) / k;
  }
  return cnt;
}

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("%lld\n", calc());
  return 0;
}
