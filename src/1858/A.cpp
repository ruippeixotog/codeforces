#include <cstdio>

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
    a += (c + 1) / 2;
    b += c / 2;
    printf("%s\n", a > b ? "First" : "Second");
  }
  return 0;
}
