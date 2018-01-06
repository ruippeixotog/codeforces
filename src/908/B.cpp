#include <algorithm>
#include <cstdio>

#define MAXN 50
#define MAXM 50
#define MAXS 100

using namespace std;

int di[] = { 0, 1, 0, -1 };
int dj[] = { 1, 0, -1, 0 };

char maze[MAXN][MAXM], s[MAXS + 1];
int is, js, ie, je;

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &maze[i][j]);
      if(maze[i][j] == 'S') { is = i; js = j; }
      if(maze[i][j] == 'E') { ie = i; je = j; }
    }
    scanf("\n");
  }
  scanf("%s", s);

  int cnt = 0, mapp[] = { 0, 1, 2, 3 };
  do {
    int i = is, j = js;
    for(int idx = 0; s[idx]; idx++) {
      i += di[mapp[s[idx] - '0']]; j += dj[mapp[s[idx] - '0']];
      if(i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '#') break;
      if(i == ie && j == je) { cnt++; break; }
    }
  } while(next_permutation(mapp, mapp + 4));

  printf("%d\n", cnt);
  return 0;
}
