#include <cstdio>

int main() {
  int y, b, r; scanf("%d %d %d\n", &y, &b, &r);

  int best;
  for(best = 98; best >= 1; best--) {
    if(y >= best && b >= best + 1 && r >= best + 2) {
      break;
    }
  }
  printf("%d\n", (best + 1) * 3);
  return 0;
}
