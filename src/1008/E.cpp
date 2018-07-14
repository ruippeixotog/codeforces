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
#include <stack>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ll n; scanf("%lld", &n);

  ll hardMinA = 1, maxA = n, hardMinB = 1, maxB = n;
  stack<pair<ll, ll>> softMins;

  int queriesLeft = 600;
  while(queriesLeft > 0) {
    ll minA = softMins.empty() ? hardMinA : max(hardMinA, softMins.top().first);
    ll minB = softMins.empty() ? hardMinB : max(hardMinB, softMins.top().second);
    ll currA = (minA + maxA) / 2, currB = (minB + maxB) / 2;

    printf("%lld %lld\n", currA, currB);
    fflush(stdout);
    queriesLeft--;

    int ans; scanf("%d", &ans);
    if(ans == 0) { return 0; }
    if(ans == 1) {
      maxA = currA - 1;
      if(currA == minA) {
        hardMinB = max(hardMinB, softMins.top().second);
        softMins.pop();
      }
    }
    else if(ans == 2) {
      maxB = currB - 1;
      if(currB == minB) {
        hardMinA = max(hardMinA, softMins.top().first);
        softMins.pop();
      }
    }
    else {
      if(currA + 1 > maxA) {
        hardMinB = max(hardMinB, currB + 1);
      } else if(currB + 1 > maxB) {
        hardMinA = max(hardMinA, currA + 1);
      } else {
        softMins.push({currA + 1, currB + 1});
      }
    }
  }
}
