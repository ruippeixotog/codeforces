#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 300000
#define MAXR 1000000000

using namespace std;

int n, k;
int l[MAXN], r[MAXN];

pair<int, int> leftSorted[MAXN], rightSorted[MAXN];
bool active[MAXN], disabled[MAXN];

bool testLen(int len) {
  if(len == 0) {
    for(int i = 0; i < k; i++) active[i] = true;
    return true;
  }

  memset(active, false, sizeof(active));
  memset(disabled, false, sizeof(disabled));

  for(int i = 0; i < n; i++) {
    if(r[i] - l[i] + 1 < len) disabled[i] = true;
  }

  int cnt = 0, lidx = 0, ridx = 0;
  while(ridx < n && disabled[rightSorted[ridx].second]) ridx++;

  while(lidx < n || ridx < n) {
    int t = min(
      lidx < n ? leftSorted[lidx].first : MAXR + 1,
      ridx < n ? rightSorted[ridx].first - len + 1 : MAXR + 1);

    while(lidx < n && leftSorted[lidx].first == t) {
      if(!disabled[leftSorted[lidx].second]) {
        active[leftSorted[lidx].second] = true;
        cnt++;
      }
      lidx++;
    }
    while(ridx < n && (rightSorted[ridx].first - len + 1) == t) {
      if(!disabled[rightSorted[ridx].second]) {
        active[rightSorted[ridx].second] = false;
        cnt--;
      }
      ridx++;
    }
    if(cnt >= k) return true;
  }
  return false;
}

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d %d\n", &l[i], &r[i]);
  }

  for(int i = 0; i < n; i++) {
    leftSorted[i] = { l[i], i };
    rightSorted[i] = { r[i] + 1, i };
  }
  sort(leftSorted, leftSorted + n);
  sort(rightSorted, rightSorted + n);

  int min = 0, max = 2 * MAXR + 1;
  while(min < max) {
    int mid = min + (max - min + 1) / 2;

    if(testLen(mid)) min = mid;
    else max = mid - 1;
  }
  testLen(min);

  printf("%d\n", min);
  for(int i = 0; k > 0; i++) {
    if(active[i]) { printf("%d ", i + 1); k--; }
  }
  printf("\n");
  return 0;
}
