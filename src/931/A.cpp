#include <cstdio>
#include <cstdlib>

int asum(int n) {
  return n * (1 + n) / 2;
}

int main() {
  int a, b; scanf("%d %d\n", &a, &b);
  int dist = abs(a - b);
  int res = asum(dist / 2) + asum(dist - dist / 2);
  printf("%d\n", res);
  return 0;
}
