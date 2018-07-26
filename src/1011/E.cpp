#include <cstdio>
#include <vector>

#define MAXK 100000

using namespace std;

bool aRev[MAXK];

vector<int> factors;
bool dp[MAXK];

int gcd(int n1, int n2) {
  return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    int ai; scanf("%d", &ai);
    aRev[gcd(ai % k, k)] = true;
  }

  for(int i = 1; i < k; i++) {
    if(!aRev[i]) continue;
    factors.push_back(i);

    for(int j = i + i; j < k; j += i) {
      aRev[j] = false;
    }
  }

  dp[0] = true;
  int cnt = 1;
  for(int fact : factors) {
    bool changed = true;
    while(changed) {
      changed = false;
      for(int i = 0; i < k; i++) {
        if(!dp[i]) continue;
        if(!dp[(i + fact) % k]) {
          dp[(i + fact) % k] = true;
          cnt++;
          changed = true;
        }
      }
    }
  }

  printf("%d\n", cnt);
  for(int i = 0; i < k; i++) {
    if(dp[i]) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
