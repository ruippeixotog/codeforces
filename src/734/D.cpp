#include <algorithm>
#include <cstdio>
#include <cstdlib>

#define MAXN 500000

using namespace std;

int xk, yk;
char piece[MAXN];
int x[MAXN], y[MAXN];

int att[3][3];

bool canAttack(int x, int y) {
  return x == xk || y == yk || abs(y - yk) == abs(x - xk);
}

int dist(int x, int y) {
  return max(abs(y - yk), abs(x - xk)); // in order to keep using ints
}

int main() {
  int n; scanf("%d %d %d\n", &n, &xk, &yk);
  for(int i = 0; i < n; i++)
    scanf("%c %d %d\n", &piece[i], &x[i], &y[i]);

  for(int i = 0; i < n; i++) {
    if(!canAttack(x[i], y[i])) continue;

    int dx = x[i] - xk, dy = y[i] - yk;
    int ux = (dx ? dx / abs(dx) : 0) + 1, uy = (dy ? dy / abs(dy) : 0) + 1;

    if(!att[ux][uy] || dist(x[i], y[i]) <
                         dist(x[att[ux][uy] - 1], y[att[ux][uy] - 1])) {
      att[ux][uy] = i + 1;
    }
  }

  bool check = false;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(att[i][j] == 0) continue;
      if(i == 1 || j == 1) check = check || piece[att[i][j] - 1] != 'B';
      else check = check || piece[att[i][j] - 1] != 'R';
    }
  }

  printf("%s\n", check ? "YES" : "NO");
  return 0;
}
