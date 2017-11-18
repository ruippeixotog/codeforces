#include <cstdio>

int main() {
  int x0, y0, x1, y1, x2, y2;
  scanf("%d %d\n%d %d\n%d %d\n", &x0, &y0, &x1, &y1, &x2, &y2);

  printf("3\n");
  printf("%d %d\n", x0 + (x2 - x1), y0 + (y2 - y1));
  printf("%d %d\n", x1 + (x0 - x2), y1 + (y0 - y2));
  printf("%d %d\n", x2 + (x1 - x0), y2 + (y1 - y0));
  return 0;
}
