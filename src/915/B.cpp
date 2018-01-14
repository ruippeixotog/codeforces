#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int n, pos, l, r; scanf("%d %d %d %d\n", &n, &pos, &l, &r);

  int res =
    l == 1 && r == n ? 0 :
    l == 1 ? abs(pos - r) + 1 :
    r == n ? abs(pos - l) + 1 :
    min(abs(pos - l), abs(pos - r)) + (r - l) + 2;

  printf("%d\n", res);
  return 0;
}
