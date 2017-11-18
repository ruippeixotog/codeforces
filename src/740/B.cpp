#include <cstdio>

#define MAXN 100

using namespace std;

int a[MAXN];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &a[i]);

  int res = 0;
  while(m--) {
    int l, r; scanf("%d %d\n", &l, &r);
    l--; r--;

    int sum = 0;
    for(int i = l; i <= r; i++) {
      sum += a[i];
    }
    if(sum > 0) res += sum;
  }
  printf("%d\n", res);
  return 0;
}
