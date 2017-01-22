#include <cstdio>

#define MAXN 200000

int p[MAXN];

bool visited[MAXN];

void visit(int i) {
  if(!visited[i]) {
    visited[i] = true;
    visit(p[i] - 1);
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  int bSum = 0;
  for(int i = 0; i < n; i++) {
    int b; scanf("%d", &b);
    bSum += b;
  }

  int loopCnt = 0;
  for(int i = 0; i < n; i++) {
    if(!visited[i]) { loopCnt++; visit(i); }
  }

  int res = (loopCnt == 1 ? 0 : loopCnt) + (bSum % 2 == 0);
  printf("%d\n", res);
  return 0;
}
