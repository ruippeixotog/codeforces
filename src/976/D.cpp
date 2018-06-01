#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int nVertices;
vector<pair<int, int>> edges;

void build(vector<int> ds) {
  if(ds.empty()) { nVertices = 1; return; }
  if(ds.size() == 1) {
    nVertices = ds[0] + 1;
    for(int i = 0; i <= ds[0]; i++) {
      for(int j = i + 1; j <= ds[0]; j++) {
        edges.emplace_back(i, j);
      }
    }
    return;
  }
  vector<int> sub;
  for(int i = 1; i < ds.size() - 1; i++) {
    sub.push_back(ds[i] - ds[0]);
  }
  build(sub);

  nVertices += ds[ds.size() - 1] - ds[ds.size() - 2];
  for(int i = 0; i < ds[0]; i++, nVertices++) {
    for(int j = 0; j < nVertices; j++) {
      edges.emplace_back(nVertices, j);
    }
  }
}

int main() {
  int n; scanf("%d\n", &n);
  vector<int> d(n, 0);
  for(int i = 0; i < n; i++)
    scanf("%d", &d[i]);

  build(d);
  printf("%d\n", (int) edges.size());
  for(auto e : edges) { printf("%d %d\n", e.first + 1, e.second + 1); }
  return 0;
}
