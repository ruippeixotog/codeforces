#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_map>

#define MAXN 3000

using namespace std;

char s[MAXN + 1];

int dpPrefix0[MAXN + 1][MAXN + 1],
  dpPrefix1[MAXN + 1][MAXN + 1],
  dpSuffix0[MAXN + 1][MAXN + 1],
  dpSuffix1[MAXN + 1][MAXN + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; scanf("%d %d\n", &n, &k);
    scanf("%[01]\n", s);

    memset(dpPrefix0[0], 0, sizeof(dpPrefix0[0]));
    memset(dpPrefix1[0], 0, sizeof(dpPrefix1[0]));

    for(int end = 1; end <= n; end++) {
      memcpy(dpPrefix0[end], dpPrefix0[end - 1], sizeof(dpPrefix0[end]));
      memcpy(dpPrefix1[end], dpPrefix1[end - 1], sizeof(dpPrefix1[end]));

      int k0 = 0, k1 = 0;
      for(int i = end - 1; i >= 0; i--) {
        s[i] == '0' ? k1++ : k0++;
        dpPrefix0[end][k0] = max(dpPrefix0[end][k0], end - i);
        dpPrefix1[end][k1] = max(dpPrefix1[end][k1], end - i);
      }
      for(int ki = 1; ki <= k; ki++) {
        dpPrefix0[end][ki] = max(dpPrefix0[end][ki], dpPrefix0[end][ki - 1]);
        dpPrefix1[end][ki] = max(dpPrefix1[end][ki], dpPrefix1[end][ki - 1]);
      }
    }
    
    memset(dpSuffix0[n], 0, sizeof(dpSuffix0[n]));
    memset(dpSuffix1[n], 0, sizeof(dpSuffix1[n]));

    for(int st = n - 1; st >= 0; st--) {
      memcpy(dpSuffix0[st], dpSuffix0[st + 1], sizeof(dpSuffix0[st]));
      memcpy(dpSuffix1[st], dpSuffix1[st + 1], sizeof(dpSuffix1[st]));

      int k0 = 0, k1 = 0;
      for(int i = st; i < n; i++) {
        s[i] == '0' ? k1++ : k0++;
        dpSuffix0[st][k0] = max(dpSuffix0[st][k0], i - st + 1);
        dpSuffix1[st][k1] = max(dpSuffix1[st][k1], i - st + 1);
      }
      for(int ki = 1; ki <= k; ki++) {
        dpSuffix0[st][ki] = max(dpSuffix0[st][ki], dpSuffix0[st][ki - 1]);
        dpSuffix1[st][ki] = max(dpSuffix1[st][ki], dpSuffix1[st][ki - 1]);
      }
    }

    unordered_map<int, int> bestForL0;
    for(int i = 0; i <= n; i++) {
      for(int ki = 0; ki <= min(k, i); ki++) {
        bestForL0[dpPrefix0[i][ki]] = max(bestForL0[dpPrefix0[i][ki]], dpSuffix1[i][k - ki]);
        bestForL0[dpSuffix0[i][k - ki]] = max(bestForL0[dpSuffix0[i][k - ki]], dpPrefix1[i][ki]);
      }
    }

    for(int a = 1; a <= n; a++) {
      int best = 0;
      for(auto p : bestForL0) {
        best = max(best, a * p.first + p.second);
      }
      printf(a == n ? "%d\n" : "%d ", best);
    }
  }
  return 0;
}
