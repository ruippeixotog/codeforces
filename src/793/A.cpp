#include <algorithm>
#include <cstdio>

#define MAXN 100000

using namespace std;

typedef long long ll;

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
