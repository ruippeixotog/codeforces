#include <cstdio>
#include <vector>

#define MAXN 1000
#define MAXK 1000

using namespace std;

int c[MAXK];
vector<int> edges[MAXN];

int totalArea = 0, maxAreaIdx = -1, area[MAXK];
bool visited[MAXN];

int ffill(int k) {
  if(visited[k]) return 0;
  visited[k] = true;

  int ar = 1;
  for(int e: edges[k]) ar += ffill(e);
  return ar;
}

int main() {
  int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
  for(int i = 0; i < k; i++) {
    scanf("%d", &c[i]); c[i]--;
  }
  for(int i = 0; i < m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    edges[--u].push_back(--v);
    edges[v].push_back(u);
  }

  for(int i = 0; i < k; i++) {
    area[i] = ffill(c[i]);
    totalArea += area[i];
    if(maxAreaIdx == -1 || area[i] > area[maxAreaIdx]) {
      maxAreaIdx = i;
    }
  }

  int unassigned = n - totalArea;
  area[maxAreaIdx] += unassigned;

  int maxEdges = 0;
  for(int i = 0; i < k; i++) {
    maxEdges += area[i] * (area[i] - 1) / 2;
  }

  printf("%d\n", maxEdges - m);
  return 0;
}
