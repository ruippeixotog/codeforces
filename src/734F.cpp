#include <cstdio>

#define bit(b) (1 << (b))
#define isset(n, b) (((n) & bit(b)) != 0)

#define MAXN 200000

using namespace std;

typedef long long ll;

int b[MAXN], c[MAXN];

int a[MAXN], bits[31];

bool calc(int n) {
  ll bcSum = 0;
  for(int i = 0; i < n; i++) {
    bcSum += b[i] + c[i];
  }

  if(bcSum % (2 * n) != 0) return false;
  ll aSum = bcSum / (2 * n);

  for(int i = 0; i < n; i++) {
    a[i] = (b[i] + c[i]) - aSum;
    if(a[i] < 0 || a[i] % n != 0) return false;
    a[i] /= n;
  }

  for(int i = 0; i < n; i++) {
    for(int b = 0; b < 31; b++) {
      bits[b] += isset(a[i], b);
    }
  }

  for(int i = 0; i < n; i++) {
    ll bTry = 0;
    for(int b = 0; b < 31; b++) {
      bTry += (ll) (isset(a[i], b) * bits[b]) << b;
    }
    if(b[i] != bTry) return false;
  }
  return true;
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &b[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &c[i]);

  bool res = calc(n);

  if(!res) printf("-1\n");
  else {
    printf("%d", a[0]);
    for(int i = 1; i < n; i++) {
      printf(" %d", a[i]);
    }
    printf("\n");
  }
  return 0;
}
