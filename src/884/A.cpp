#include <cstdio>

#define MAXN 100

int a[MAXN];

int main() {
  int n, t; scanf("%d %d\n", &n, &t);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int day = 0, left = t;
  while(left > 0) {
    left -= 86400 - (day < n ? a[day] : 0);
    day++;
  }
  printf("%d\n", day);
  return 0;
}
