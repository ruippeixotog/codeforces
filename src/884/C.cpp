#include <algorithm>
#include <cstdio>
#include <functional>

#define MAXN 100000

using namespace std;

typedef long long ll;

int p[MAXN];

int cycles[MAXN];
bool visited[MAXN];

int visit(int k) {
  if(visited[k]) return 0;
  visited[k] = true;
  return 1 + visit(p[k]);
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i]); p[i]--;
  }

  for(int i = 0; i < n; i++) {
    cycles[i] = visit(i);
  }
  sort(cycles, cycles + n, greater<int>());

  ll conv = (cycles[0] + cycles[1]) * (ll) (cycles[0] + cycles[1]);
  for(int i = 2; i < n; i++) {
    conv += cycles[i] * (ll) cycles[i];
  }
  printf("%lld\n", conv);
  return 0;
}
