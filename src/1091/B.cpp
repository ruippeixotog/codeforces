#include <cstdio>
#include <set>

#define MAXN 1000

using namespace std;

set<pair<int, int>> xy;

int a[MAXN], b[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    xy.insert({ x, y });
  }
  for(int i = 0; i < n; i++)
    scanf("%d %d", &a[i], &b[i]);

  pair<int, int> res;
  for(auto pair : xy) {
    res.first = pair.first + a[0];
    res.second = pair.second + b[0];

    bool found = true;
    for(int i = 0; i < n; i++) {
      if(!xy.count({ res.first - a[i], res.second - b[i] })) {
        found = false;
        break;
      }
    }
    if(found) {
      break;
    }
  }
  printf("%d %d\n", res.first, res.second);
  return 0;
}
