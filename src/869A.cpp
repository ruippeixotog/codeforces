#include <cstdio>
#include <set>

#define MAXN 2000

using namespace std;

int x[MAXN], y[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &x[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &y[i]);

  set<int> s;
  for(int i = 0; i < n; i++) {
    s.insert(x[i]);
    s.insert(y[i]);
  }

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cnt += s.count(x[i] ^ y[j]);
    }
  }
  printf("%s\n", cnt % 2 ? "Koyomi" : "Karen");
  return 0;
}
