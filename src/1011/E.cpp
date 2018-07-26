#include <cstdio>

#define MAXK 100000

bool dp[MAXK];

int gcd(int n1, int n2) {
  return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

int main() {
  int n, k; scanf("%d %d\n", &n, &k);

  int aGcd = k;
  for(int i = 0; i < n; i++) {
    int ai; scanf("%d", &ai);
    aGcd = gcd(aGcd, ai);
  }

  dp[0] = true;
  int cnt = 1;
  for(int i = 0; i + aGcd < k; i++) {
    if(!dp[i]) continue;
    if(!dp[i + aGcd]) {
      dp[i + aGcd] = true;
      cnt++;
    }
  }

  printf("%d\n", cnt);
  for(int i = 0; i < k; i++) {
    if(dp[i]) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
