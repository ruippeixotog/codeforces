#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 4000
#define INF 1000000000

using namespace std;

int n, a[MAXN];

int aSum[MAXN + 1];
int dp[MAXN][200][100];

int calc2(int, int, int);

int calc1(int i, int j, int k) {
  if(i > j) return INF;
  if(i + k > j) return aSum[i] - (aSum[n] - aSum[j]);

  int dij = i - (n - j);
  if(dp[i][dij + 100][k] < INF) return dp[i][dij + 100][k];

  return dp[i][dij + 100][k] = max(
    calc2(i + k, j, k),
    calc2(i + k + 1, j, k + 1));
}

int calc2(int i, int j, int k) {
  if(i > j) return -INF;
  if(i > j - k) return aSum[i] - (aSum[n] - aSum[j]);
  return min(
    calc1(i, j - k, k),
    calc1(i, j - k - 1, k + 1));
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  aSum[0] = 0;
  for(int i = 1; i <= n; i++)
    aSum[i] = aSum[i - 1] + a[i - 1];

  memset(dp, 0x3f, sizeof(dp));
  int res = calc1(0, n, 1);

  printf("%d\n", res);
  return 0;
}
