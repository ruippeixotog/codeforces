#include <algorithm>
#include <cstdio>

#define MAXN 400000

using namespace std;

typedef long long ll;

int a[MAXN];

int ab[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int res = 0;
  for(int b = 0; b < 25; b++) {
    int mask = (1 << (b + 1)) - 1;

    for(int i = 0; i < n; i++) {
      ab[i] = a[i] & mask;
    }
    sort(ab, ab + n);

    ll cnt = 0;
    for(int i = 0; i < n; i++) {
      int a0 = ab[i];
      auto lower1 = lower_bound(ab + i + 1, ab + n, (1 << b) - a0);
      auto upper1 = lower_bound(ab + i + 1, ab + n, (1 << (b + 1)) - a0);
      auto lower2 = lower_bound(ab + i + 1, ab + n, (0b11 << b) - a0);
      auto upper2 = ab + n;
      cnt += (upper1 - lower1) + (upper2 - lower2);
    }
    res |= (cnt & 1) << b;
  }

  printf("%d\n", res);
  return 0;
}
