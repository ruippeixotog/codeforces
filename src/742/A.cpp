#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int n; scanf("%d\n", &n);
  int digit = n == 0 ? 1 : (int) pow(8, (n - 1) % 4 + 1) % 10;
  printf("%d\n", digit);
  return 0;
}
