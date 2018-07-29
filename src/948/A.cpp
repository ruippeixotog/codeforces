#include <cstdio>

#define MAXR 500
#define MAXC 500

char grid[MAXR][MAXC];

bool go(int r, int c) {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(grid[i][j] == 'S') {
        if((i > 0 && grid[i - 1][j] == 'W') ||
           (j > 0 && grid[i][j - 1] == 'W') ||
           (i < r - 1 && grid[i + 1][j] == 'W') ||
           (j < c - 1 && grid[i][j + 1] == 'W')) return false;
      }
    }
  }
  return true;
}

int main() {
  int r, c; scanf("%d %d\n", &r, &c);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%c", &grid[i][j]);
    }
    scanf("\n");
  }

  bool safe = go(r, c);

  printf("%s\n", safe ? "Yes" : "No");
  if(safe) {
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        printf("%c", grid[i][j] == '.' ? 'D' : grid[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
