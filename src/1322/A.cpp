#include <cstdio>

#define MAXN 1000000

char str[MAXN + 1];

int main() {
  int n; scanf("%d\n", &n);
  scanf("%s", str);

  int depth = 0, total = 0, beginSeq = -1;
  for(int i = 0; i < n; i++) {
    if(str[i] == ')') {
      if(depth == 0) {
        beginSeq = i;
      }
      depth--;
    }
    else {
      depth++;
      if(depth == 0) {
        total += i - beginSeq + 1;
      }
    }
  }
  printf("%d\n", depth == 0 ? total : -1);
  return 0;
}
