#include <algorithm>
#include <cstdio>

#define MAXN 100

using namespace std;

int a[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] < 0) continue;
    cnt++;

    for(int j = i + 1; j < n; j++) {
      if(a[j] % a[i] == 0) {
        a[j] = -1;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
