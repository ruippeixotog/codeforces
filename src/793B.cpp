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
#define MAXM 1000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
char grid[MAXN][MAXM];

bool search2(int i0, int j0, int di, int dj) {
  for(int i = i0 + di, j = j0 + dj;
      i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '*';
      i += di, j += dj) {

    if(grid[i][j] == ':' || grid[i][j] == 'T') return true;
  }
  return false;
}

bool search1(int i0, int j0, int di, int dj) {
  for(int i = i0 + di, j = j0 + dj;
      i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '*';
      i += di, j += dj) {

    if(grid[i][j] == ':' || grid[i][j] == 'T' ||
      search2(i, j, dj, di) || search2(i, j, -dj, -di))
      return true;
  }
  return false;
}

int main() {
  scanf("%d %d\n", &n, &m);
  int si = -1, sj = -1, ti = -1, tj = -1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &grid[i][j]);
      if(grid[i][j] == 'S') { si = i; sj = j; }
      if(grid[i][j] == 'T') { ti = i; tj = j; }
    }
    scanf("\n");
  }

  for(int j = tj - 1; j >= 0 && grid[ti][j] == '.'; j--) grid[ti][j] = ':';
  for(int j = tj + 1; j < m && grid[ti][j] == '.'; j++) grid[ti][j] = ':';
  for(int i = ti - 1; i >= 0 && grid[i][tj] == '.'; i--) grid[i][tj] = ':';
  for(int i = ti + 1; i < n && grid[i][tj] == '.'; i++) grid[i][tj] = ':';

//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < m; j++) {
//      printf("%c", grid[i][j]);
//    }
//    printf("\n");
//  }

  bool res = search1(si, sj, 1, 0) || search1(si, sj, -1, 0) ||
    search1(si, sj, 0, 1) || search1(si, sj, 0, -1);

  printf("%s\n", res ? "YES" : "NO");
  return 0;
}
