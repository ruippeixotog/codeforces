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

#define MAXN 1000000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

map<int, int> mem;

int largestPrimeFactor(int k) {
  if(mem[k]) return mem[k];

  for(int i = 2; i <= (int) sqrt(k); i++) {
    if(k % i != 0) continue;
    return mem[k] = max(largestPrimeFactor(i), largestPrimeFactor(k / i));
  }
  return mem[k] = k;
}

int n;
map<int, int> factors;
vector<ll> res;

void go(map<int, int>::iterator it, ll multiplier) {
  if(it == factors.end()) {
    ll an = n / multiplier;
    ll sum = an * (2 + (an - 1) * multiplier) / 2;
    res.push_back(sum);
    return;
  }
  for(int i = 0; i <= it->second; i++, multiplier *= it->first) {
    go(next(it), multiplier);
  }
}

int main() {
  scanf("%d\n", &n);

  int tmp = n;
  while(tmp > 1) {
    int fact = largestPrimeFactor(tmp);
    factors[fact]++;
    tmp /= fact;
  }
  go(factors.begin(), 1);
  sort(res.begin(), res.end());

  for(ll r : res) {
    printf("%lld ", r);
  }
  printf("\n");
  return 0;
}
