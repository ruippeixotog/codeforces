#include <algorithm>
#include <cstdio>

using namespace std;

bool a[10], b[10];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    int ai; scanf("%d", &ai); a[ai] = true;
  }
  for(int i = 0; i < m; i++) {
    int bi; scanf("%d", &bi); b[bi] = true;
  }

  int res = -1, minA = 10, minB = 10;
  for(int i = 0; i < 10; i++) {
    if(a[i] && b[i]) { res = i; break; }
    if(a[i]) minA = min(minA, i);
    if(b[i]) minB = min(minB, i);
  }
  if(res == -1) {
    res = min(minA, minB) * 10 + max(minA, minB);
  }
  printf("%d\n", res);
  return 0;
}
