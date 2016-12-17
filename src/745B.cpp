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

#define MAXN 500
#define MAXM 500
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
char piece[MAXN][MAXM];

bool isRect() {
  int v0i = -1, v0j = -1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(piece[i][j] == 'X') {
        v0i = i; v0j = j;
        break;
      }
    }
    if(v0i >= 0) break;
  }

  int v1i = -1, v1j = -1;
  for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if(piece[i][j] == 'X') {
        v1i = i; v1j = j;
        break;
      }
    }
    if(v1i >= 0) break;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {

      if((piece[i][j] == 'X') !=
        (i >= v0i && i <= v1i && j >= v0j && j <= v1j)) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &piece[i][j]);
    }
    scanf("\n");
  }

  printf("%s\n", isRect() ? "YES" : "NO");
  return 0;
}
