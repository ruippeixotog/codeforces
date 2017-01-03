#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define MAXH 7

using namespace std;

int queries;
vector<int> adjs[(1 << MAXH) - 1];
bool locked[(1 << MAXH) - 1];

int path1[MAXH * 2], path2[MAXH * 2];

int question(int node) {
  printf("? %d\n", node + 1);
  fflush(stdout);
  queries++;

  int k; scanf("%d", &k);
  if(!k) exit(0);

  for(int i = 0; i < k; i++) {
    int t; scanf("%d", &t);
    adjs[node].push_back(t - 1);
  }
  return k;
}

void answer(int node) {
  printf("! %d\n", node + 1);
  fflush(stdout);
}

int visit(int node, int parent, int depth, int maxDepth, int *path, bool lockAll) {
  if(depth == maxDepth) return -2;
  path[depth] = node;
  if(lockAll) locked[node] = true;

  if(adjs[node].empty()) {
    if(queries == 16) { answer(node); return -1; }
    int k = question(node);
    if(k == 1) return depth;
    if(k == 2) { answer(node); return -1; }
  }

  for(int adj: adjs[node]) {
    if(adj != parent && !locked[adj]) {
      int res = visit(adj, node, depth + 1, maxDepth, path, lockAll);
      if(res != -2) return res;
    }
  }
  return -2;
}

int visitPath(int node, int maxDepth, int *path, bool lockAll) {
  return visit(node, -1, 0, maxDepth, path, lockAll);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int h; scanf("%d", &h);
    if(!h) exit(0);

    // reset state
    queries = 0;
    memset(locked, false, sizeof(locked));
    for(int i = 0; i < (1 << h) - 1; i++)
      adjs[i].clear();

    // follow two paths beginning on a starting node (0)
    int d1 = visitPath(0, 2 * h, path1, true);
    if(d1 < 0) continue;
    int d2 = visitPath(0, 2 * h, path2, true);
    if(d2 < 0) continue;

    // set `curr` as the first common ancestor of the two (on depth `d1`)
    int curr = 0, i = 0;
    while(d1 < d2) { curr = path2[++i]; d1++; d2--; }
    while(d2 < d1) { curr = path1[++i]; d1--; d2++; }

    // follow paths from `curr` until the root or a leaf is reached
    while((d2 = visitPath(curr, h - d1, path1, false)) >= 0) {
      // if a leaf was found set `curr` as the new common ancestor
      i = 0;
      while(d1 < d2) { curr = path1[++i]; d1++; d2--; }
      locked[path1[i - 1]] = locked[path1[i + 1]] = true;
    }
  }
  return 0;
}
