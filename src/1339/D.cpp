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

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> adjs[MAXN];

int level = 0;
bool oddDepths, evenDepths;

void dfs(int k, int last, int depth) {
  if(last != -1) {
    level++;
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
    level++;
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  for(int i = 0; i < n; i++) {
    if(adjs[i].size() > 1) {
      dfs(i, -1, 0);
      break;
    }
  }

  int minF = oddDepths & evenDepths ? 3 : 1;
  int maxF = level;

  printf("%d %d\n", minF, maxF);
  return 0;
}
