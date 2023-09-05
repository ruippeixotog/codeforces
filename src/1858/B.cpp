#include <cstdio>

#define MAXM 100000

int s[MAXM];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m, d; scanf("%d %d %d\n", &n, &m, &d);
    for(int i = 0; i < m; i++) {
      scanf("%d\n", &s[i]);
      s[i]--;
    }

    int curr = 1, cnt = 0;
    for(int i = 0; i < m; i++) {
      if(s[i] == 0) continue;

      int prev = i == 0 ? 0 : s[i - 1];
      int next = i == m - 1 ? n : s[i + 1];

      int with = (s[i] - prev - 1) / d + 1 + (next - s[i] - 1) / d;
      int without = (next - prev - 1) / d; 

      if(without < with) {
        cnt++;
      }
      curr += (s[i] - prev - 1) / d + 1;
    }
    curr += (n - s[m - 1] - 1) / d;

    printf("%d %d\n", cnt ? curr - 1 : curr, cnt ? cnt : m);
  }
  return 0;
}
