#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 80
#define MAXK 80
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int c[MAXN][MAXN];

int dp[MAXK][MAXN][MAXN][MAXN];

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  int m; scanf("%d\n", &m);
  for(int i = 0; i < n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    scanf("%d\n", &c[u - 1][v - 1]);
  }

  memset(dp, 0x3f, sizeof(dp));
  for(int i = 0; i < n; i++) {
    dp[0][i][0][n - 1] = 0;
  }

  for(int ka = 0; ka < k - 1; ka++) {
    for(int i = 0; i < n; i++) {
      for(int iMin = 0; iMin < n; iMin++) {
        for(int iMax = 0; iMax < n; iMax++) {
          if(dp[ka][i][iMin][iMax] == INF) continue;

          for(int i2 = i + 1; i2 <= iMax; i2++) {
            if(!c[i][i2]) continue;
//            cerr << "dp[" << (ka + 1) << "][" << i2 << "]["<< (i + 1) << "][" << iMax << "]" << endl;

            dp[ka + 1][i2][i + 1][iMax] = min(
              dp[ka + 1][i2][i + 1][iMax],
              dp[ka][i][iMin][iMax] + c[i][i2]);
          }
          for(int i2 = i - 1; i2 >= iMin; i2--) {
            if(!c[i][i2]) continue;
//            cerr << "dp[" << (ka + 1) << "][" << i2 << "]["<< (i + 1) << "][" << iMax << "]" << endl;

            dp[ka + 1][i2][iMin][i - 1] = min(
              dp[ka + 1][i2][iMin][i - 1],
              dp[ka][i][iMin][iMax] + c[i][i2]);
          }
        }
      }
    }
  }

  int best = INF;
  for(int i = 0; i < n; i++) {
    for(int iMin = 0; iMin < n; iMin++) {
      for(int iMax = 0; iMax < n; iMax++) {
        best = min(best, dp[k - 1][i][iMin][iMax]);
      }
    }
  }

  printf("%d\n", best == INF ? -1 : best);
  return 0;
}
