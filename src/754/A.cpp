#include <cstdio>

#define MAXN 100

int a[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int nz = n, sum = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != 0 && nz == n) nz = i;
    sum += a[i];
  }

  if(sum == 0 && nz == n) {
    printf("NO\n");
  } else {
    printf("YES\n");

    if(sum != 0) {
      printf("1\n1 %d\n", n);
    } else {
      printf("2\n1 %d\n%d %d\n", nz + 1, nz + 2, n);
    }
  }
  return 0;
}
