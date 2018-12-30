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

#define MAXN 1000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

set<pair<int, int>> xy;

//int x[MAXN], y[MAXN];
int a[MAXN], b[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    xy.insert({ x, y });
//    scanf("%d %d", &x[i], &y[i]);
  }
  for(int i = 0; i < n; i++)
    scanf("%d %d", &a[i], &b[i]);

  pair<int, int> res;
  for(auto pair : xy) {
    int tx = pair.first + a[0];
    int ty = pair.second + b[0];

    bool found = true;
    for(int i = 0; i < n; i++) {
      if(!xy.count({ tx - a[i], ty - b[i] })) {
        found = false;
        break;
      }
    }
    if(found) {
      res = { tx, ty };
      break;
    }
  }
  printf("%d %d\n", res.first, res.second);
  return 0;
}
