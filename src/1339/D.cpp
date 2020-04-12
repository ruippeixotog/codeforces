#include <cstdio>
#include <vector>

#define MAXN 100000

using namespace std;

vector<int> adjs[MAXN];

int maxDistinct = 0;
bool oddDepths, evenDepths;

void dfs(int k, int last, int depth) {
  if(last != -1) {
    maxDistinct++;
  }
  bool hasLeaves = false;
  for(int adj : adjs[k]) {
    if(adj == last) continue;

    if(adjs[adj].size() == 1) {
      hasLeaves = true;
      (depth % 2 ? oddDepths : evenDepths) = true;
    } else {
      dfs(adj, k, depth + 1);
    }
  }
  if(hasLeaves) {
    maxDistinct++;
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    adjs[--a].push_back(--b);
    adjs[b].push_back(a);
  }

  for(int i = 0; i < n; i++) {
    if(adjs[i].size() > 1) {
      dfs(i, -1, 0);
      break;
    }
  }
  int minDistinct = oddDepths & evenDepths ? 3 : 1;
  printf("%d %d\n", minDistinct, maxDistinct);
  return 0;
}
