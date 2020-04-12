#include <algorithm>
#include <cstdio>

#define MAXN 100000

using namespace std;

int a[MAXN];

int numBits(int n) {
  int bits = 0;
  for(; n > 0; bits++, n /= 2) {}
  return bits;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    int curr = a[0];
    int maxSeconds = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] < curr) {
        maxSeconds = max(maxSeconds, numBits(curr - a[i]));
      } else if(a[i] > curr) {
        curr = a[i];
      }
    }
    printf("%d\n", maxSeconds);
  }
  return 0;
}
