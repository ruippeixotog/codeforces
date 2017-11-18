#include <cstdio>

#define INF 0x3f3f3f3f

int n, a[2][5], solved[5];

int calcMaxValue(int solvers, int participants) {
  if(2 * solvers > participants) return 500;
  else if(4 * solvers > participants) return 1000;
  else if(8 * solvers > participants) return 1500;
  else if(16 * solvers > participants) return 2000;
  else if(32 * solvers > participants) return 2500;
  return 3000;
}

int calcScore(int t, int maxValue) {
  return t == INF ? 0 : maxValue - t * maxValue / 250;
}

bool canWin(int extra) {
  int diff = 0;
  for(int i = 0; i < 5; i++) {
    bool isBest = a[0][i] <= a[1][i];
    int maxValue = calcMaxValue(
      isBest || a[0][i] == INF ? solved[i] : solved[i] + extra,
      n + extra);

    diff += calcScore(a[0][i], maxValue) - calcScore(a[1][i], maxValue);
  }
  return diff > 0;
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      int t; scanf("%d", &t);
      if(i < 2) a[i][j] = t == -1 ? INF : t;
      solved[j] += (t >= 0);
    }
  }

  int res;
  for(res = 0; res < 5000; res++) {
    if(canWin(res)) break;
  }
  printf("%d\n", res == 5000 ? -1 : res);
  return 0;
}
