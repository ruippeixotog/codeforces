#include <algorithm>
#include <cstdio>

#define MAXN 200000

using namespace std;

typedef long long ll;

int a[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    ll curr = a[0], shift = 0, steps = 0;
    for(int i = 1; i < n; i++) {
      ll ai = a[i] - shift;
      steps += abs(ai - curr);
      ai <= curr ? curr = ai : shift += ai - curr;
    }
    steps += abs(curr);
    printf("%lld\n", steps);
  }
  return 0;
}
