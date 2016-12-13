#include <cstdio>

#define MAXN 100000
#define MAXA 100000

using namespace std;

typedef long long ll;

int a[MAXN];

int hist[MAXA + 1];

int main() {
  int n, x; scanf("%d %d\n", &n, &x);
  for(int i = 0; i < n; i++) {
    scanf("%d\n", &a[i]);
    hist[a[i]]++;
  }

  ll cnt = 0;
  for(int i = 0; i <= MAXA; i++) {
    int j = x ^ i;
    if(j > MAXA) continue;
    cnt += hist[i] * (ll) (hist[j] - (i == j));
  }
  printf("%lld\n", cnt / 2);
  return 0;
}
