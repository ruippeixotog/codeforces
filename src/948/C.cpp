#include <cstdio>
#include <queue>

#define MAXN 100000

using namespace std;

typedef long long ll;

int v[MAXN], t[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &t[i]);

  priority_queue<ll, vector<ll>, greater<ll>> heights;
  ll baseline = 0;
  for(int i = 0; i < n; i++) {
    heights.push(baseline + v[i]);

    ll shrinked = 0;
    while(!heights.empty() && heights.top() <= baseline + t[i]) {
      shrinked += heights.top() - baseline;
      heights.pop();
    }
    shrinked += heights.size() * t[i];
    printf("%lld ", shrinked);
    baseline += t[i];
  }
  printf("\n");
  return 0;
}
