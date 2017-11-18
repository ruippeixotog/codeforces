#include <algorithm>
#include <cstdio>

#define MAXN 200000

using namespace std;

char frac[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%c", &frac[i]);

  int alive[2], elim[2] = {0, 0};
  alive[0] = count(frac, frac + n, 'D');
  alive[1] = n - alive[0];

  for(int i = 0; alive[0] > 0 && alive[1] > 0; i = (i + 1) % n) {
    if(frac[i] == '-') continue;
    int f = frac[i] == 'R';

    if(elim[f] > 0) { elim[f]--; frac[i] = '-'; alive[f]--; }
    else elim[1 - f]++;
  }

  printf("%c\n", alive[0] > 0 ? 'D' : 'R');
  return 0;
}
