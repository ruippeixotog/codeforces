#include <algorithm>
#include <cmath>
#include <cstring>

#define MAXN 1000000

using namespace std;

int mem[MAXN + 1];

int largestPrimeFactor(int k) {
  if(mem[k]) return mem[k];

  for(int i = 2; i <= (int) sqrt(k); i++) {
    if(k % i != 0) continue;
    return mem[k] = max(largestPrimeFactor(i), largestPrimeFactor(k / i));
  }
  return mem[k] = k;
}

int main() {
  int x2; scanf("%d\n", &x2);

  int fx2 = largestPrimeFactor(x2);
  int x0 = x2;
  for(int x1 = x2 - fx2 + 1; x1 <= x2; x1++) {
    int fx1 = largestPrimeFactor(x1);
    if(fx1 < x1) {
      x0 = min(x0, x1 - fx1 + 1);
    }
  }
  printf("%d\n", x0);
  return 0;
}
