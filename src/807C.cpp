#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll x, y, p, q; scanf("%lld %lld %lld %lld\n", &x, &y, &p, &q);

    ll res = 0;
    if(p == 0) {
      res = x == 0 ? 0 : -1;
    } else if(q == 1) {
      res = x == y ? 0 : -1;
    } else {
      if(x == 0) { x += 1; y += 1; res = 1; }
      ld y0 = x * q / (ld) p;

      ll x1 = x + (y0 >= y ? 0 : (ll) std::ceil((y * p - q * x) / (ld) (q - p)));
      x1 = p * (ll) ceil(x1 / (ld) p);
      ll y1 = x1 / p * q;

      res += y1 - y;
    }
    printf("%lld\n", res);
  }
  return 0;
}
