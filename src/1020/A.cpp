#include <cstdio>
#include <cstdlib>

int main() {
  int n, h, a, b, k;
  scanf("%d %d %d %d %d\n", &n, &h, &a, &b, &k);
  while(k--) {
    int ta, fa, tb, fb;
    scanf("%d %d %d %d\n", &ta, &fa, &tb, &fb);

    int cost = 0;
    if(ta != tb) {
      cost += abs(ta - tb);
      if(fa < a) {
        cost += a - fa;
        fa = a;
      } else if(fa > b) {
        cost += fa - b;
        fa = b;
      }
    }
    cost += abs(fa - fb);
    printf("%d\n", cost);
  }
  return 0;
}
