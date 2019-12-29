#include <algorithm>
#include <cstdio>

#define MAXN 100

using namespace std;

char s[MAXN + 1];
int a[MAXN], b[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  scanf("%s\n", s);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &a[i], &b[i]);

  int bestCnt = 0;
  for(int t = 1; t <= 200; t++) { // 5 + 5! steps should be enough
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      cnt += s[i] == '1';
    }
    bestCnt = max(bestCnt, cnt);

    for(int i = 0; i < n; i++) {
      if(t >= b[i] && (t - b[i]) % a[i] == 0) {
        s[i] = s[i] == '1' ? '0' : '1';
      }
    }
  }
  printf("%d\n", bestCnt);
  return 0;
}
