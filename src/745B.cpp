#include <algorithm>
#include <cstdio>

#define MAXN 500
#define MAXM 500

using namespace std;

int n, m;
char piece[MAXN][MAXM];

bool isRect() {
  int iMin = n, iMax = -1, jMin = m, jMax = -1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(piece[i][j] == 'X') {
        iMin = min(iMin, i); iMax = max(iMax, i);
        jMin = min(jMin, j); jMax = max(jMax, j);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if((piece[i][j] == 'X') !=
        (i >= iMin && i <= iMax && j >= jMin && j <= jMax)) return false;
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
