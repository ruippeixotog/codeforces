#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int n; ll a, b, c;
  scanf("%d %lld %lld %lld\n", &n, &a, &b, &c);

  ll res = 0;
  switch(n % 4) {
    case 1:
      res = min(c, min(a + b, a * 3));
      break;
    case 2:
      res = min(b, min(c * 2, a * 2));
      break;
    case 3:
      res = min(a, min(b + c, c * 3));
  }

  printf("%lld\n", res);
  return 0;
}
