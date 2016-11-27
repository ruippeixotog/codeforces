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

#define MAXN 200000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[90];

int main() {
  ll n; scanf("%lld\n", &n);

  dp[0] = 1;
  dp[1] = 2;
  for(int i = 2; i < 90; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  int i = 1;
  while(n >= dp[i + 1]) i++;

  printf("%d\n", i);
  return 0;
}
