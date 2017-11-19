#include <cstdio>

#define MAXM 1000

int s[MAXM];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int m; scanf("%d\n", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &s[i]);
  }

  bool possible = true;
  for(int i = 1; i < m; i++) {
    if(gcd(s[i], s[0]) != s[0]) { possible = false; break; }
  }

  if(possible) {
    printf("%d\n", m * 2 - 1);
    printf("%d", s[0]);
    for(int i = 1; i < m; i++) printf(" %d %d", s[i], s[0]);
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
