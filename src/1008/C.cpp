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

int a[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);
  queue<int> open;
  for(int i = 0; i < n; i++) {
    if(!open.empty() && open.front() < a[i]) {
      open.pop();
    }
    open.push(a[i]);
  }
  printf("%d\n", n - (int) open.size());
  return 0;
}
