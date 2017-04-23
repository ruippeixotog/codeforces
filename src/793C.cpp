#include <algorithm>
#include <cstdio>

#define MAXN 100000
#define INF 0x3f3f3f3f

using namespace std;

typedef long double ld;

int rx[MAXN], ry[MAXN], vx[MAXN], vy[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  int x1, y1, x2, y2; scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
  for(int i = 0; i < n; i++)
    scanf("%d %d %d %d\n", &rx[i], &ry[i], &vx[i], &vy[i]);

  if(x1 > x2) swap(x1, x2);
  if(y1 > y2) swap(y1, y2);

  ld tMin = 0, tMax = INF;
  for(int i = 0; i < n; i++) {
    if(vx[i] == 0) {
      if(rx[i] <= x1 || rx[i] >= x2) tMax = -INF;
    } else {
      ld tx1 = (x1 - rx[i]) / (ld) vx[i];
      ld tx2 = (x2 - rx[i]) / (ld) vx[i];
      if(tx1 > tx2) swap(tx1, tx2);

      tMin = max(tMin, tx1);
      tMax = min(tMax, tx2);
    }

    if(vy[i] == 0) {
      if(ry[i] <= y1 || ry[i] >= y2) tMax = -INF;
    } else {
      ld ty1 = (y1 - ry[i]) / (ld) vy[i];
      ld ty2 = (y2 - ry[i]) / (ld) vy[i];
      if(ty1 > ty2) swap(ty1, ty2);

      tMin = max(tMin, ty1);
      tMax = min(tMax, ty2);
    }
  }

  ld res = tMin >= tMax ? -1 : tMin;
  printf("%.9lf\n", (double) res);
  return 0;
}
