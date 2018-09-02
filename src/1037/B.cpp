#include <algorithm>
#include <cstdio>

#define MAXN 200000

using namespace std;

typedef long long ll;

int a[MAXN];

int main() {
  int n, s; scanf("%d %d\n", &n, &s);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);

  ll ops = 0;
  for(int i = n / 2; i >= 0 && a[i] > s; i--) {
    ops += a[i] - s;
  }
  for(int i = n / 2; i < n && a[i] < s; i++) {
    ops += s - a[i];
  }
  printf("%lld\n", ops);
  return 0;
}
