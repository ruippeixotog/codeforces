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

#define MAXN 1000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n, L[MAXN];

map<int, int> dist[MAXN];

inline int parent(int k) { return (k - 1) / 2; }
inline int left(int k) { return k * 2 + 1; }
inline int right(int k) { return k * 2 + 2; }
inline int getLen(int to) { return to < n ? L[to - 1] : 0; }

void calcDist(int k) {
  dist[k][0] = 1;

  if(left(k) < n) {
    calcDist(left(k));
    for(auto it : dist[left(k)]) {
      dist[k][getLen(left(k)) + it.first] += it.second;
    }
  }
  if(right(k) < n) {
    calcDist(right(k));
    for(auto it : dist[right(k)]) {
      dist[k][getLen(right(k)) + it.first] += it.second;
    }
  }
}

ll querySibling(int a, int h) {
  if(a >= n || h <= 0) return 0;
  ll happiness = 0;
  for(auto it : dist[a]) {
    if(it.first >= h) break;
    happiness += it.second * (ll) (h - it.first);
  }
  return happiness;
}

ll queryParent(int a, int h, int child) {
  if(a == child || h <= 0) return 0;

  ll happiness = child == left(a) ?
                 h + querySibling(right(a), h - getLen(right(a))) :
                 h + querySibling(left(a), h - getLen(left(a)));

  happiness += queryParent(parent(a), h - getLen(a), a);
  return happiness;
}

ll query(int a, int h) {
  return querySibling(a, h) + queryParent(parent(a), h - getLen(a), a);
}

int main() {
  int m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n - 1; i++)
    scanf("%d", &L[i]);

  calcDist(0);
//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < 21; j++) {
//      cerr << dist[i][j] << " ";
//    }
//    cerr << endl;
//  }

  for(int i = 0; i < m; i++) {
    int a, h; scanf("%d %d\n", &a, &h);
//    cerr << "query: " << a << " " << h << endl;
    printf("%lld\n", query(a - 1, h));
  }
  return 0;
}
