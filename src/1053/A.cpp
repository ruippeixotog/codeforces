#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int n, m, k; scanf("%d %d %d\n", &n, &m, &k);

  int resX = -1, resY = -1;
  if(2LL * n * m % k == 0) {
    ll target = 2LL * n * m / k;
    int high = max(n, m);

    for(ll x = (target + high - 1) / high; x <= target / x; x++) {
      if(target % x == 0) {
        resX = (int) x; resY = (int) (target / x);
        break;
      }
    }
    if(n > m) {
      swap(resX, resY);
    }
  }
  if(resX >= 0) {
    printf("YES\n");
    printf("0 0\n");
    printf("%d 0\n", resX);
    printf("0 %d\n", resY);
  } else {
    printf("NO\n");
  }
  return 0;
}
