#include <cstdio>

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int m, d; scanf("%d %d\n", &m, &d);

  int weeks = (monthDays[m - 1] + d - 1 + 6) / 7;
  printf("%d\n", weeks);
  return 0;
}
