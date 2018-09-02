#include <cstdio>

int main() {
  int n; scanf("%d\n", &n);
  int packets = 0;
  while(n > 0) {
    packets++;
    n /= 2;
  }
  printf("%d\n", packets);
  return 0;
}
