#include <cstdio>
#include <vector>

#define MAXN 200000

using namespace std;

int color[MAXN];
vector<int> adjs[MAXN];

int lowest, height;

void dfp(int k, int parent, int depth) {
  if(depth > height) {
    height = depth;
    lowest = k;
  }
  for(int adj : adjs[k]) {
    if(adj == parent) continue;
    dfp(adj, k, depth + (color[adj] != color[k]));
  }
}

void dfp0(int root) {
  lowest = height = 0;
  dfp(root, -1, 0);
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &color[i]);

  for(int i = 0; i < n - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adjs[--u].push_back(--v);
    adjs[v].push_back(u);
  }

  dfp0(0);
  dfp0(lowest);

  int moves = (height + 1) / 2;
  printf("%d\n", moves);
  return 0;
}
