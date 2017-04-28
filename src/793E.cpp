#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 5000

using namespace std;

int n, abcd[4];
vector<int> adjs[MAXN];

int ttag[MAXN], tsize[MAXN];
bool dp[MAXN][MAXN];

void processTree(int k, int parent) {
  if(adjs[k].size() == 1) {
    tsize[k] = 1;
    for(int i = 0; i < 4; i++) {
      if(k + 1 == abcd[i]) { ttag[k] = i + 1; break; }
    }
    return;
  }
  for(int adj: adjs[k]) {
    if(adj != parent) {
      processTree(adj, k);
      tsize[k] += tsize[adj];
      ttag[k] |= ttag[adj];
    }
  }
}

void addSubtreeObjs(vector<int>& objs, int k, int parent) {
  for(int adj: adjs[k]) {
    if(adj != parent) {
      if(!ttag[adj]) objs.push_back(tsize[adj]);
      else addSubtreeObjs(objs, adj, k);
    }
  }
}

bool knapsack(int ac, int bd) {
  vector<int> objs;
  for(int sroot: adjs[0]) {
    if(ttag[sroot] == ac || ttag[sroot] == bd) addSubtreeObjs(objs, sroot, 0);
    else objs.push_back(tsize[sroot]);
  }

  memset(dp, false, sizeof(dp));
  dp[0][0] = true;
  for(int i = 0; i < objs.size(); i++) {
    for(int j = 0; j < n; j++) {
      if(dp[i][j]) {
        dp[i + 1][j] = dp[i + 1][j + objs[i]] = true;
      }
    }
  }
  return dp[objs.size()][(tsize[0] - 2) / 2];
}

int main() {
  scanf("%d\n", &n);
  scanf("%d %d %d %d\n", &abcd[0], &abcd[1], &abcd[2], &abcd[3]);
  for(int i = 1; i < n; i++) {
    int p; scanf("%d", &p);
    adjs[p - 1].push_back(i);
    adjs[i].push_back(p - 1);
  }

  processTree(0, -1);
  bool res = tsize[0] % 2 == 0 && knapsack(1, 2) && knapsack(3, 4);
  printf("%s\n", res ? "YES" : "NO");
  return 0;
}
