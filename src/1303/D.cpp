#include <cmath>
#include <cstdio>
#include <cstring>

#define MAXN 100000

typedef long long ll;

int a[MAXN];

int stock[64];

int ensureStock(int order) {
  if(order == 64) return -1;
  if(stock[order]) return 0;

  int res = ensureStock(order + 1);
  if(res == -1) return -1;
  stock[order + 1]--;
  stock[order] += 2;
  return res + 1;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll n, m; scanf("%lld %lld\n", &n, &m);
    for(int i = 0; i < m; i++)
      scanf("%d", &a[i]);

    memset(stock, 0, sizeof(stock));
    for(int i = 0; i < m; i++) {
      stock[(int) log2(a[i])]++;
    }

    bool fail = false;
    int divisions = 0, order = 0;
    while(n > 0) {
      if(order > 0) {
        stock[order] += stock[order - 1] / 2;
      }
      if(n % 2 == 1) {
        int res = ensureStock(order);
        if(res == -1) {
          fail = true;
          break;
        }
        divisions += res;
        stock[order]--;
      }
      n /= 2;
      order++;
    }
    printf("%d\n", fail ? -1 : divisions);
  }
  return 0;
}
