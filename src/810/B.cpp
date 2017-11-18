#include <algorithm>
#include <cstdio>
#include <functional>

#define MAXN 100000

using namespace std;

typedef long long ll;

int k[MAXN], l[MAXN];

int pot[MAXN];

int main() {
  int n, f; scanf("%d %d\n", &n, &f);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &k[i], &l[i]);

  ll sum = 0;
  for(int i = 0; i < n; i++) {
    sum += min(k[i], l[i]);
    pot[i] = min(k[i] * 2, l[i]) - min(k[i], l[i]);
  }
  sort(pot, pot + n, greater<int>());
  for(int i = 0; i < f; i++) {
    sum += pot[i];
  }
  printf("%lld\n", sum);
  return 0;
}
