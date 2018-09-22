#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cmath>

#define MAXN 300000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

bool nonPrime[3874]; // sqrt(MAXA)

int gcd(int n1, int n2) {
  return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int d = a[0];
  for(int i = 1; i < n; i++) {
    d = gcd(d, a[i]);
  }
  for(int i = 0; i < n; i++) {
    a[i] /= d;
  }

  map<int, int> factors;
  for(int i = 2; i < 3874; i++) {
    if(nonPrime[i]) continue;

    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(a[j] % i == 0) cnt++;
    }
    if(cnt > 0) {
      factors[i] = cnt;
    }
    for(int j = i + i; j < 3874; j += i) {
      nonPrime[j] = true;
    }
  }

  int high = 0;
  for(auto e : factors) {
    high = max(high, e.second);
  }
  printf("%d\n", high > 0 ? n - high : -1);
  return 0;
}
