#include <cstdio>
#include <vector>

#define MAXN 1000
#define MAXM 1000

using namespace std;

vector<int> rows[MAXN], cols[MAXM];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int a; scanf("%d", &a);
      if(a) {
        rows[i].push_back(j);
        cols[j].push_back(i);
      }
    }
  }

  int cnt = 0;

  for(int i = 0; i < n; i++) {
    if(rows[i].empty()) continue;
    cnt += rows[i][0];
    for(int j = 1; j < rows[i].size(); j++) {
      cnt += 2 * (rows[i][j] - rows[i][j - 1] - 1);
    }
    cnt += m - rows[i].back() - 1;
  }

  for(int i = 0; i < m; i++) {
    if(cols[i].empty()) continue;
    cnt += cols[i][0];
    for(int j = 1; j < cols[i].size(); j++) {
      cnt += 2 * (cols[i][j] - cols[i][j - 1] - 1);
    }
    cnt += n - cols[i].back() - 1;
  }

  printf("%d\n", cnt);
  return 0;
}
