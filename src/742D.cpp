#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 1000
#define MAXW 1000

using namespace std;

int w[MAXN], b[MAXN];

vector<int> groups[MAXN];
int dp[MAXN + 1][MAXW + 1];

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
};

int main() {
  int n, m, wMax; scanf("%d %d %d\n", &n, &m, &wMax);
  for(int i = 0; i < n; i++)
    scanf("%d", &w[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &b[i]);

  UnionFind uf(n);
  while(m--) {
    int x, y; scanf("%d %d\n", &x, &y);
    uf.join(x - 1, y - 1);
  }

  for(int i = 0; i < n; i++)
    groups[uf.get(i)].push_back(i);

  int best = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= wMax; j++) {
      int dpBest = dp[i - 1][j];

      int wGroup = 0, bGroup = 0;
      for(int e: groups[i - 1]) {
        wGroup += w[e]; bGroup += b[e];
        if(j - w[e] >= 0) {
          dpBest = max(dpBest, dp[i - 1][j - w[e]] + b[e]);
        }
      }
      if(j - wGroup >= 0) {
        dpBest = max(dpBest, dp[i - 1][j - wGroup] + bGroup);
      }
      dp[i][j] = dpBest;
      best = max(best, dpBest);
    }
  }

  printf("%d\n", best);
  return 0;
}
