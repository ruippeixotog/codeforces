#include <cstdio>
#include <queue>
#include <set>
#include <vector>

#define MAXN 200000
#define MAXM 200000

using namespace std;

int n, m, k;
int x[MAXM], y[MAXM];

set<int> adjs[MAXN];
int validCnt = 0;
queue<int> q;

void removeEdge(int u, int v) {
  if(!adjs[u].count(v)) return;
  adjs[u].erase(v);
  if(adjs[u].size() == k - 1) {
    q.push(u);
    validCnt--;
  }
}

void processQueue() {
  while(!q.empty()) {
    int v = q.front();
    for(int adj : adjs[v]) {
      removeEdge(adj, v);
    }
    adjs[v].clear();
    q.pop();
  }
}

int main() {
  scanf("%d %d %d\n", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    scanf("%d %d\n", &x[i], &y[i]);
    adjs[--x[i]].insert(--y[i]);
    adjs[y[i]].insert(x[i]);
  }

  for(int i = 0; i < n; i++) {
    if(adjs[i].size() < k) q.push(i);
    else validCnt++;
  }
  processQueue();

  vector<int> res = { validCnt };
  for(int i = m - 1; i > 0; i--) {
    removeEdge(x[i], y[i]);
    removeEdge(y[i], x[i]);
    processQueue();
    res.push_back(validCnt);
  }
  for(int i = m - 1; i >= 0; i--) {
    printf("%d\n", res[i]);
  }
  return 0;
}
