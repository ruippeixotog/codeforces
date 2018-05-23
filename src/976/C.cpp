#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>

#define MAXN 300000

using namespace std;

pair<int, int> lr[MAXN];

int ord[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &lr[i].first, &lr[i].second);

  iota(ord, ord + n, 0);
  sort(ord, ord + n, [](int i0, int i1) { return lr[i0] < lr[i1]; });

  int ai = -2, aj = -2;
  for(int i = 1; i < n; i++) {
    if(lr[ord[i - 1]].first == lr[ord[i]].first) {
      ai = ord[i - 1]; aj = ord[i]; break;
    }
    if(lr[ord[i - 1]].second >= lr[ord[i]].second) {
      ai = ord[i]; aj = ord[i - 1]; break;
    }
  }
  printf("%d %d\n", ai + 1, aj + 1);
  return 0;
}
