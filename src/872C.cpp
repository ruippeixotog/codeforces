#include <cstdio>

int main() {
  int q; scanf("%d\n", &q);
  while(q--) {
    int n; scanf("%d", &n);

    int res = -1;
    switch(n % 4) {
      case 0:
        res = n / 4;
        break;
      case 1:
        if(n > 8) res = n / 4 - 1;
        break;
      case 2:
        if(n > 4) res = n / 4;
        break;
      case 3:
        if(n > 12) res = n / 4 - 1;
        break;
    }
    printf("%d\n", res);
  }
  return 0;
}
