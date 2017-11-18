#include <cstdio>

using namespace std;

int main() {
  int n, k; scanf("%d %d\n", &n, &k);

  int maxT = 4 * 60 - k;
  int i = 0, t = 0;
  while(i < n && t + 5 * (i + 1) <= maxT) {
    t += 5 * (i + 1);
    i++;
  }

  printf("%d\n", i);
  return 0;
}
