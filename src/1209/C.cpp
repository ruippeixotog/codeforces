#include <cstdio>

#define MAXN 200000

char d[MAXN];
char color[MAXN];

void solve() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%c", &d[i]);
    d[i] -= '0';
  }
  for(int sep = 0; sep < 10; sep++) {
    int curr1 = 0, curr2 = sep;
    bool valid = true;
    for(int i = 0; i < n; i++) {
      color[i] = d[i] <= sep ? '1' : '2';
      if(d[i] == sep && d[i] == curr2) {
        color[i] = '2';
        continue;
      } else if(d[i] <= sep) {
        if(d[i] < curr1) { valid = false; break; }
        else curr1 = d[i];
      } else if(d[i] > sep) {
        if(d[i] < curr2) { valid = false; break; }
        else curr2 = d[i];
      }
    }
    if(valid) {
      for(int i = 0; i < n; i++) {
        printf("%c", color[i]);
      }
      printf("\n");
      return;
    }
  }
  printf("-\n");
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 0; tc < t; tc++) {
    solve();
  }
  return 0;
}
