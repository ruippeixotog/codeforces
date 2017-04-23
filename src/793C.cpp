#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int rx[MAXN], ry[MAXN], vx[MAXN], vy[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  int x1, y1, x2, y2; scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
  for(int i = 0; i < n; i++)
    scanf("%d %d %d %d\n", &rx[i], &ry[i], &vx[i], &vy[i]);

  int tmp1 = min(x1, x2), tmp2 = max(x1, x2);
  x1 = tmp1; x2 = tmp2;
  tmp1 = min(y1, y2), tmp2 = max(y1, y2);
  y1 = tmp1; y2 = tmp2;

//  cerr << "x = [" << x1 << "," << x2 << "]" << endl;
//  cerr << "y = [" << y1 << "," << y2 << "]" << endl;

  ld tMin = 0, tMax = INF;
  for(int i = 0; i < n; i++) {
    if(vx[i] == 0) {
      if(rx[i] <= x1 || rx[i] >= x2) { tMax = -INF; }
    } else {
      ld tx1 = (x1 - rx[i]) / (ld) vx[i];
      ld tx2 = (x2 - rx[i]) / (ld) vx[i];
      ld tmp1 = min(tx1, tx2), tmp2 = max(tx1, tx2);
      tx1 = tmp1, tx2 = tmp2;

//      cerr << "tx = [" << tx1 << "," << tx2 << "]" << endl;
      tMin = max(tMin, tx1);
      tMax = min(tMax, tx2);
    }

    if(vy[i] == 0) {
      if(ry[i] <= y1 || ry[i] >= y2) { tMax = -INF; }
    } else {
      ld ty1 = (y1 - ry[i]) / (ld) vy[i];
      ld ty2 = (y2 - ry[i]) / (ld) vy[i];
      ld tmp1 = min(ty1, ty2), tmp2 = max(ty1, ty2);
      ty1 = tmp1, ty2 = tmp2;

//      cerr << "ty = [" << ty1 << "," << ty2 << "]" << endl;
      tMin = max(tMin, ty1);
      tMax = min(tMax, ty2);
    }
  }

  ld res = tMin >= tMax ? -1 : tMin;
  printf("%.9lf\n", (double) res);
  return 0;
}
