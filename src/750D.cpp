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

#define MAXN 30
#define MAXG 500
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, t[MAXN];

bool visited[MAXG][MAXG];
int visitedCount = 0;

bool expanded[MAXG][MAXG][8][MAXN];

void go(int i, int j, int dir, int depth) {
  if(depth == n) return;

  if(expanded[i][j][dir][depth]) return;
  expanded[i][j][dir][depth] = true;

  for(int k = 0; k < t[depth]; k++) {
    i += di[dir]; j += dj[dir];

    if(i < 0 || j < 0 || i >= MAXG || j >= MAXG)
      cerr << i << " " << j << endl;

    if(!visited[i][j]) {
      visited[i][j] = true;
      visitedCount++;
    }
  }
  go(i, j, (dir + 1) % 8, depth + 1);
  go(i, j, (dir + 7) % 8, depth + 1);
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d\n", &t[i]);

  go(MAXG / 2, MAXG / 2, 0, 0);
  printf("%d\n", visitedCount);
  return 0;
}
