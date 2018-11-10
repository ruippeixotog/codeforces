#include <algorithm>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int la, ra, ta; scanf("%d %d %d\n", &la, &ra, &ta);
  int lb, rb, tb; scanf("%d %d %d\n", &lb, &rb, &tb);

  if(ta > tb) {
    swap(la, lb); swap(ra, rb); swap(ta, tb);
  }

  int g = gcd(ta, tb);

  int ka = (lb - la + g - 1) / g;
  int lak = la + ka * g;
  int rak = ra + ka * g;
  int best = max(0, min(rak, rb) - max(lak, lb) + 1);

  lak = la + (ka - 1) * g;
  rak = ra + (ka - 1) * g;
  best = max(best, min(rak, rb) - max(lak, lb) + 1);

  printf("%d\n", best);
  return 0;
}
