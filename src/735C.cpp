#include <cstdio>

using namespace std;

typedef long long ll;

ll dp[100];

int main() {
  ll n; scanf("%lld\n", &n);

  dp[0] = 1;
  dp[1] = 2;

  int i = 1;
  while(n >= dp[i]) {
    dp[i + 1] = dp[i] + dp[i - 1];
    i++;
  }

  printf("%d\n", i - 1);
  return 0;
}
