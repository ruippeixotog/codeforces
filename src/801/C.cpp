#include <algorithm>
#include <cstdio>
#include <tuple>

#define MAXN 100000

using namespace std;

typedef long long ll;
typedef long double ld;

tuple<ld, ll, ll> dev[MAXN];

int main() {
  int n, p; scanf("%d %d\n", &n, &p);
  for(int i = 0; i < n; i++) {
    int a, b; scanf("%d %d\n", &a, &b);
    dev[i] = make_tuple(b / (ld) a, a, b);
  }
  sort(dev, dev + n);

  int i = 0;
  for(; i < n - 1; i++) {
    ld needed = get<1>(dev[i]) - get<2>(dev[i]) / get<0>(dev[i + 1]);
    if(needed > p) break;

    get<1>(dev[i + 1]) += get<1>(dev[i]);
    get<2>(dev[i + 1]) += get<2>(dev[i]);
  }

  ld res = p >= get<1>(dev[i]) ? -1.0 :
           get<2>(dev[i]) / (ld) (get<1>(dev[i]) - p);

  printf("%.9f\n", (double) res);
  return 0;
}
