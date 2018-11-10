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

int a[MAXN], b[MAXN];

int main() {
  int n, s; scanf("%d %d\n", &n, &s);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &b[i]);

  bool possible = false;
  if(a[0] && a[s - 1]) {
    possible = true;
  } else {
    for(int i = s; i < n; i++) {
      if(a[0] && a[i] && b[i] && b[s - 1]) {
        possible = true;
        break;
      }
    }
  }
  printf("%s\n", possible ? "YES" : "NO");
  return 0;
}
