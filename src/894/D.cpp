#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 1000000

using namespace std;

typedef long long ll;

int n, L[MAXN];

vector<ll> dist[MAXN], sumDist[MAXN];

inline int parent(int k) { return (k - 1) / 2; }
inline int left(int k) { return k * 2 + 1; }
inline int right(int k) { return k * 2 + 2; }

void calcDist(int k) {
  dist[k].push_back(0);

  vector<ll> l, r;
  if(left(k) < n) {
    calcDist(left(k));
    copy(dist[left(k)].begin(), dist[left(k)].end(), back_inserter(l));
    for (ll &li : l) li += L[left(k) - 1];
  }
  if(right(k) < n) {
    calcDist(right(k));
    copy(dist[right(k)].begin(), dist[right(k)].end(), back_inserter(r));
    for (ll &ri : r) ri += L[right(k) - 1];
  }
  merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(dist[k]));

  for(int i = 0; i < dist[k].size(); i++) {
    sumDist[k].push_back(dist[k][i] + (i == 0 ? 0 : sumDist[k][i - 1]));
  }
}

ll queryChildren(int a, int h) {
  if(a >= n || h <= 0) return 0;

  auto it = lower_bound(dist[a].begin(), dist[a].end(), h);
  if(it == dist[a].end() || *it > h) it--;
  int idx = (int) (it - dist[a].begin());

  return h * (ll) (idx + 1) - sumDist[a][idx];
}

ll queryParent(int a, int h, int child) {
  if(a == child || h <= 0) return 0;

  ll happiness = child == left(a) ?
                 h + queryChildren(right(a), h - L[right(a) - 1]) :
                 h + queryChildren(left(a), h - L[left(a) - 1]);

  happiness += queryParent(parent(a), h - L[a - 1], a);
  return happiness;
}

ll query(int a, int h) {
  return queryChildren(a, h) + queryParent(parent(a), h - L[a - 1], a);
}

int main() {
  int m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n - 1; i++)
    scanf("%d", &L[i]);

  calcDist(0);

  for(int i = 0; i < m; i++) {
    int a, h; scanf("%d %d\n", &a, &h);
    printf("%lld\n", query(a - 1, h));
  }
  return 0;
}
