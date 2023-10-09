#include <algorithm>
#include <cstdio>

#define MAXN 50

using namespace std;

int a[MAXN], b[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, x; scanf("%d %d\n", &n, &x);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &a[i]);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &b[i]);

    sort(a, a + n);
    sort(b, b + n);

    bool valid = true;
    for(int i = 0; i < n; i++) {
      if(a[i] + b[n - i - 1] > x) {
        valid = false;
        break;
      }
    }
    printf("%s\n", valid ? "Yes" : "No");
  }
  return 0;
}
