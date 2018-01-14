#include <cstdio>

int main() {
  int n, k; scanf("%d %d\n", &n, &k);

  int best = k;
  for(int i = 0; i < n; i++) {
    int ai; scanf("%d", &ai);
    if(k % ai == 0 && k / ai < best)
      best = k / ai;
  }
  printf("%d\n", best);
  return 0;
}
