#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
  m -= n;

  int st = 0, end = m;
  while(st < end) {
    int mid = (st + end + 1) / 2;

    int lside = min(k - 1, mid - 1);
    int rside = min(n - k, mid - 1);

    ll needed = mid +
      lside * (ll) ((mid - lside) + (mid - 1)) / 2 +
      rside * (ll) ((mid - rside) + (mid - 1)) / 2;

    if(needed > m) end = mid - 1;
    else st = mid;
  }

  printf("%d\n", st + 1);
  return 0;
}
