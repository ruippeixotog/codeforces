#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

bool isPrime(int n) {
  int max = ceil(sqrt(n));
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
