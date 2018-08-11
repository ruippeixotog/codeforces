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

int p[MAXN];

bool visited[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  for(int i = 0; i < n; i++) {
    memset(visited, false, sizeof(visited));
    int curr = i;
    while(!visited[curr]) {
      visited[curr] = true;
      curr = p[curr] - 1;
    }
    printf("%d ", curr + 1);
  }
  return 0;
}
