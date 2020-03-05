#include <cstdio>

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    while(n > 0) {
      if(n % 2 == 1) {
        printf("7");
        n -= 3;
      } else {
        printf("1");
        n -= 2;
      }
    }
    printf("\n");
  }
  return 0;
}
