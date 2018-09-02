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

#define MAXN 1000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

char a[MAXN + 1], b[MAXN + 1];

int main() {
  int n; scanf("%d\n", &n);
  scanf("%s\n", a);
  scanf("%s\n", b);

  int ops = 0;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] != a[i] && a[i - 1] == b[i] && a[i] == b[i - 1]) {
      swap(a[i - 1], a[i]);
      ops++;
      i++;
    }
  }
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) ops++;
  }
  printf("%d\n", ops);
  return 0;
}
