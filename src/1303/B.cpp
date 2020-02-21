#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, g, b; scanf("%d %d %d\n", &n, &g, &b);

    ll res = n;
    if(g < b) {
      ll target = (n + 1) / 2;
      ll its = (target + g - 1) / g - 1;
      res = max(res, target + its * b);
    }
    printf("%lld\n", res);
  }
  return 0;
}
