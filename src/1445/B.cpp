#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int a, b, c, d; scanf("%d %d %d %d\n", &a, &b, &c, &d);
    printf("%d\n", max(a + b, c + d));
  }
  return 0;
}
