#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 100000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

int main() {
  int n, n1, n2; scanf("%d %d %d\n", &n, &n1, &n2);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &a[i]);

  int nSmall = min(n1, n2);
  int nLarge = max(n1, n2);
  sort(a, a + n);

  int idx = n - 1;
  ll sum = 0.0;
  for(int i = 0; i < nSmall; i++) {
    sum += nLarge * (ll) a[idx--];
  }
  for(int i = 0; i < nLarge; i++) {
    sum += nSmall * (ll) a[idx--];
  }
  ld avg = sum / (ld) (n1 * (ll) n2);

  cout.precision(17);
  cout << fixed << avg << endl;
  return 0;
}
