#include <cstdio>

int main() {
  int n, x; scanf("%d %d\n", &n, &x);

  int sum = 0;
  for(int i = 0; i < n; i++) {
    int ai; scanf("%d", &ai); sum += ai;
  }
  printf("%s\n", x - sum == n - 1 ? "YES" : "NO");
  return 0;
}
