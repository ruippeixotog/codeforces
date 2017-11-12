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
#define MAXA 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

bool visited[MAXA + 1];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int last = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(!visited[a[i]]) {
      visited[a[i]] = true;
      last = a[i];
    }
  }
  printf("%d\n", last);
  return 0;
}
