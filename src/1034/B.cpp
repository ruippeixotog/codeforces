#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int n, m; scanf("%d %d\n", &n, &m);

  int low = min(n, m), high = max(n, m);
  int res;

  if(low == 1) {
    res = min(high % 6, 6 - high % 6);

  } else if(low == 2) {
    if(high == 2) res = 4;
    else if(high == 3 || high == 7) res = 2;
    else res = 0;

  } else {
    res = low % 2 == 0 || high % 2 == 0 ? 0 : 1;
  }

  printf("%lld\n", (n * (ll) m) - res);
  return 0;
}
