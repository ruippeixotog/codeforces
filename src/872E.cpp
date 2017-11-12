#include <cstdio>
#include <map>
#include <set>

#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

map<int, set<int>> xs, ys;

map<int, map<int, bool>> visited;
set<int> seenX, seenY;

bool dfs2(int i, int j, int prevDir) {
  if(visited[i][j]) return false;
  visited[i][j] = true;
  seenX.insert(i); seenY.insert(j);

  bool res = true;
  auto itx = xs[i].find(j), ity = ys[j].find(i);

  if(prevDir != 1 && itx != xs[i].begin()) {
    res &= dfs2(i, *prev(itx), 3);
  }
  if(prevDir != 3 && next(itx) != xs[i].end()) {
    res &= dfs2(i, *next(itx), 1);
  }
  if(prevDir != 2 && ity != ys[j].begin()) {
    res &= dfs2(*prev(ity), j, 4);
  }
  if(prevDir != 4 && next(ity) != ys[j].end()) {
    res &= dfs2(*next(ity), j, 2);
  }
  return res;
}

bool dfs(int i, int j) {
  seenX.clear(); seenY.clear();
  return dfs2(i, j, -1);
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    int x, y; scanf("%d %d\n", &x, &y);
    xs[x].insert(y); ys[y].insert(x);
  }

  int cnt = 1;
  for (auto &e : xs) {
    bool isAcyclic = dfs(e.first, *e.second.begin());
    if(!seenX.empty()) {
      cnt = (int) mmul(cnt, madd(
        mpow(2, seenX.size() + seenY.size()),
        isAcyclic ? MOD - 1 : 0));
    }
  }
  printf("%d\n", cnt);
  return 0;
}
