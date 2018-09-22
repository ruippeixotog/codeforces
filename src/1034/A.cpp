#include <cstdio>

#define MAXN 300000
#define MAXA 15000000

int a[MAXN];

int factor[MAXA + 1], cnt[MAXA + 1];

int gcd(int n1, int n2) {
  return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

int main() {
  for(int i = 2; i <= MAXA; i++) {
    if(factor[i]) continue;
    factor[i] = i;
    for(int j = i + i; j <= MAXA; j += i) {
      factor[j] = i;
    }
  }

  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int g = a[0];
  for(int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
  }

  for(int i = 0; i < n; i++) {
    a[i] /= g;
    while(a[i] > 1) {
      int p = factor[a[i]];
      cnt[p]++;
      while(a[i] % p == 0) {
        a[i] /= p;
      }
    }
  }

  int high = 0;
  for(int i = 2; i <= MAXA; i++) {
    if(cnt[i] > high) high = cnt[i];
  }
  printf("%d\n", high > 0 ? n - high : -1);
  return 0;
}
