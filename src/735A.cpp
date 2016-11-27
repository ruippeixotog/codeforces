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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

char line[MAXN];
int n, k, g, t;

bool visited[MAXN];

bool dfs(int i) {
  if(i == t) return true;
  if(i < 0 || i >= n || visited[i] || line[i] == '#') return false;

  visited[i] = true;
  return dfs(i - k) || dfs(i + k);
}

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%c", &line[i]);
    if(line[i] == 'G') { g = i; line[i] = '.'; }
    if(line[i] == 'T') { t = i; line[i] = '.'; }
  }

  bool res = dfs(g);
  printf("%s\n", res ? "YES" : "NO");
  return 0;
}
