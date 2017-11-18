#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  ll a, b; scanf("%lld %lld\n", &a, &b);

  int value = 1;
  while(value > 0 && a < b) {
    value = (value * (int) (++a % 10)) % 10;
  }
  printf("%d\n", value);
  return 0;
}
