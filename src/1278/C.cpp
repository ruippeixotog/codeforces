#include <algorithm>
#include <cstdio>
#include <unordered_map>

#define MAXN 100000

using namespace std;

int a[2 * MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < 2 * n; i++)
      scanf("%d", &a[i]);

    unordered_map<int, int> seenLeft;
    int balance = 0;
    seenLeft[0] = 0;
    for(int i = 0; i < n; i++) {
      balance += a[i] == 1 ? 1 : -1;
      seenLeft[balance] = i + 1;
    }
    balance = 0;
    int best = seenLeft[0];
    for(int i = 0; i < n; i++) {
      balance += a[2 * n - i - 1] == 1 ? 1 : -1;
      if(seenLeft.count(-balance)) {
        best = max(best, i + 1 + seenLeft[-balance]);
      }
    }
    printf("%d\n", 2 * n - best);
  }
  return 0;
}
