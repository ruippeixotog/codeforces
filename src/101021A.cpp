#include <cstdio>

#define MAXN 1000000

using namespace std;

char op[3];

int main() {
  int min = 1, max = MAXN;
  while(min < max) {
    int mid = (min + max + 1) / 2;
    printf("%d\n", mid); fflush(stdout);
    scanf("%s", op);

    if(op[0] == '<') max = mid - 1;
    else min = mid;
  }
  printf("! %d\n", min);
  fflush(stdout);
  return 0;
}
