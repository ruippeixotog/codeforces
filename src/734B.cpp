#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int k2, k3, k5, k6; scanf("%d %d %d %d\n", &k2, &k3, &k5, &k6);

  int n256 = min(k2, min(k5, k6));
  int n32 = min(k3, k2 - n256);

  int sum = n256 * 256 + n32 * 32;
  printf("%d\n", sum);
}
