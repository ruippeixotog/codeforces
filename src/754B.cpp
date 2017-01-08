#include <cstdio>

int di[] = {1, 0, 1, 1};
int dj[] = {0, 1, 1, -1};

char grid[4][4];

bool winsOn(int i, int j, int dir) {
  bool missing = false;
  for(int k = 0; k < 3; k++, i += di[dir], j += dj[dir]) {
    if(grid[i][j] == 'o') return false;
    if(grid[i][j] == '.') {
      if(!missing) missing = true;
      else return false;
    }
  }
  return missing;
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      scanf("%c", &grid[i][j]);
    }
    scanf("\n");
  }

  bool wins = false;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i < 2) wins = wins || winsOn(i, j, 0);
      if(j < 2) wins = wins || winsOn(i, j, 1);
      if(i < 2 && j < 2) wins = wins || winsOn(i, j, 2);
      if(i < 2 && j >= 2) wins = wins || winsOn(i, j, 3);
    }
  }
  printf("%s\n", wins ? "YES" : "NO");
  return 0;
}
