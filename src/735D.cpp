#include <cmath>
#include <cstdio>

using namespace std;

bool isPrime(int n) {
  double max = sqrt(n);
  for(int i = 2; i <= max; i++) {
    if(n % i == 0) return false;
  }
  return true;
}

int main() {
  int n; scanf("%d\n", &n);

  int res =
    n <= 3 || isPrime(n) ? 1 :
    n % 2 == 0 || isPrime(n - 2) ? 2 :
    3;

  printf("%d\n", res);
  return 0;
}
