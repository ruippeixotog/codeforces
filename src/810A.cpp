#include <cstdio>

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a); sum += a;
  }
  int nh = n;
  while(sum / (double) nh < k - 0.5) {
    sum += k; nh++;
  }
  printf("%d\n", nh - n);
  return 0;
}
