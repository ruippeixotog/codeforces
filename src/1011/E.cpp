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

#define MAXN 100000
#define MAXK 100000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];
bool aRev[MAXK];

vector<int> factors;

bool dp[MAXK];

int gcd(int n1, int n2) {
  return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    aRev[gcd(a[i], k) % k] = true;
  }

  for(int i = 1; i < k; i++) {
    if(!aRev[i]) continue;
    factors.push_back(i);

    for(int j = i + i; j < k; j += i) {
      aRev[j] = false;
    }
  }

  dp[0] = true;
  for(int fact : factors) {
    for(int i = 0; i + fact < k; i++) {
      if(!dp[i]) continue;
      dp[i + fact] = true;
    }
  }

  int cnt = 0;
  for(int i = 0; i < k; i++) {
    if(dp[i]) cnt++;
  }

  printf("%d\n", cnt);
  for(int i = 0; i < k; i++) {
    if(dp[i]) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
