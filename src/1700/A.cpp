#include <cstdio>

typedef long long ll;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m; scanf("%d %d\n", &n, &m);

    ll steps = 0;
    for(int i = 0; i < m; i++) steps += i + 1;
    for(int i = 1; i < n; i++) steps += (i + 1) * (ll) m;
    printf("%lld\n", steps);
  }
  return 0;
}
