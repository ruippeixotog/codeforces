#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAXS 400
#define MAXT 400

using namespace std;

string s, t;

int main() {
  int tcc; scanf("%d\n", &tcc);
  for(int tc = 1; tc <= tcc; tc++) {
    getline(cin, s);
    getline(cin, t);

    bool found = false;
    for(int sep = 0; sep < t.size() && !found; sep++) {
      int dp[MAXS + 1][MAXT + 1];
      memset(dp, -1, sizeof(dp));
      dp[0][sep] = 0;

      for(int i = 0; i < s.size(); i++) {
        for(int j = sep; j <= t.size(); j++) {
          if(dp[i][j] == -1) continue;

          dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
          if(j < t.size() && s[i] == t[j]) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
          }
          if(dp[i][j] < sep && s[i] == t[dp[i][j]]) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
          }
        }
      }
      if(dp[s.size()][t.size()] == sep) {
        found = true;
      }
    }
    printf("%s\n", found ? "YES" : "NO");
  }
  return 0;
}
