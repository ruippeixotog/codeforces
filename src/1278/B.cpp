#include <algorithm>
#include <cstdio>

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int a, b; scanf("%d %d\n", &a, &b);

    int diff = abs(a - b);
    int sum = 0, curr = 0;
    while(sum < diff || (sum - diff) % 2 == 1) {
      sum += ++curr;
    }
    printf("%d\n", curr);
  }
  return 0;
}
