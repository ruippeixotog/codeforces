#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#define MAXN 500000

using namespace std;

struct UnionFind {
  int pset[MAXN];
  int rank[MAXN];

  UnionFind() {}
  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i = 0; i < n; i++) {
      pset[i] = i;
      rank[i] = 0;
    }
  }

  int get(int i) {
    return (pset[i] == i) ? i : (pset[i] = get(pset[i]));
  }

  void join(int i, int j) {
    int xRoot = get(i);
    int yRoot = get(j);
    if (xRoot == yRoot) return;
    if (rank[xRoot] < rank[yRoot])
      pset[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
      pset[yRoot] = xRoot;
    else {
      pset[yRoot] = xRoot;
      rank[xRoot] = rank[xRoot] + 1;
    }
  }

  bool sameSet(int i, int j) {
    return get(i) == get(j);
  }
};

pair<int, int> lr[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d", &lr[i].first, &lr[i].second);

  sort(lr, lr + n);

  map<int, vector<int>> ends;
  UnionFind uf(n);
  bool failed = false;
  int edges = 0;
  for(int i = 0; i < n && !failed; i++) {
    while(!ends.empty() && ends.begin()->first <= lr[i].first) {
      ends.erase(ends.begin());
    }
    auto end = ends.lower_bound(lr[i].second);
    for(auto it = ends.begin(); it != end && !failed; it++) {
      for(int adj : it->second) {
        if(uf.sameSet(i, adj)) {
          failed = true;
        }
        edges++;
        uf.join(i, adj);
      }
    }
    ends[lr[i].second].push_back(i);
  }
  printf("%s\n", failed || edges != n - 1 ? "NO" : "YES");
  return 0;
}
