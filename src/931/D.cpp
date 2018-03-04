#include <cstdio>
#include <queue>
#include <vector>

#define MAXN 100000

using namespace std;

vector<int> children[MAXN];

int alias[MAXN];
queue<bool> fruits[MAXN];

void compress(int k) {
  alias[k] = k;
  if(children[k].size() != 1) {
    for(int adj : children[k]) compress(adj);
    return;
  }
  int adj = children[k][0];
  children[k].pop_back();
  alias[adj] = k;

  for(int dadj : children[adj]) {
    children[k].push_back(dadj);
  }
  compress(k);
}

int drop(int k) {
  int v = fruits[k].front();
  fruits[k].pop();

  bool isActive = false; int tailV = 0;
  for(int adj : children[k]) {
    if(!fruits[adj].empty()) {
      tailV += drop(adj);
      isActive = true;
    }
  }
  if(isActive) {
    fruits[k].push((bool) (tailV % 2));
  }
  return v;
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n - 1; i++) {
    int parent; scanf("%d", &parent);
    children[--parent].push_back(i + 1);
  }

  compress(0);
  for(int i = 0; i < n; i++)
    fruits[alias[i]].push(true);

  int collected = 0;
  while(!fruits[0].empty()) {
    collected += drop(0);
  }
  printf("%d\n", collected);
  return 0;
}
