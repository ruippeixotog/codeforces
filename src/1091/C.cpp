#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int n;

map<int, int> factors;
vector<ll> res;

map<int, int> _mem;

int largestPrimeFactor(int k) {
  if(_mem[k]) return _mem[k];

  for(int i = 2; i <= (int) sqrt(k); i++) {
    if(k % i != 0) continue;
    return _mem[k] = max(largestPrimeFactor(i), largestPrimeFactor(k / i));
  }
  return _mem[k] = k;
}

void go(map<int, int>::iterator it, ll multiplier) {
  if(it == factors.end()) {
    ll an = n / multiplier;
    res.push_back(an * (2 + (an - 1) * multiplier) / 2);
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
