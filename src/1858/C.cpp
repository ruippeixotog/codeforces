#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);

    vector<int> res;
    for(int st = 1; st <= n; st += 2) {
      for(int curr = st; curr <= n; curr *= 2) {
        res.push_back(curr);
      }
    }
    printf("%d", res[0]);
    for(int i = 1; i < n; i++) {
      printf(" %d", res[i]);
    }
    printf("\n");
  }
  return 0;
}
