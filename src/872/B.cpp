#include <algorithm>
#include <cstdio>

#define MAXN 100000
#define INF 0x3f3f3f3f

using namespace std;

int a[MAXN];
int maxa, minl[MAXN], minr[MAXN];

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  maxa = a[0]; minl[0] = a[0]; minr[n - 1] = a[n - 1];
  for(int i = 1; i < n; i++) {
    maxa = max(maxa, a[i]);
    minl[i] = min(minl[i - 1], a[i]);
    minr[n - i - 1] = min(minr[n - i], a[n - i - 1]);
  }

  int res = -INF;
  if(k == 1) res = min(minl[n - 1], minr[0]);
  else if(k >= 3) res = maxa;
  else {
    for(int i = 1; i < n; i++) {
      res = max(res, max(minl[i - 1], minr[i]));
    }
  }
  printf("%d\n", res);
  return 0;
}
