#include <cstdio>

#define MAXN 1000

int a[MAXN], b[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d\n", &a[i], &b[i]);

  int last = 5000;
  bool unsorted = false, unequal = false;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) unequal = true;
    if(a[i] > last) unsorted = true;
    last = a[i];
  }
  printf("%s\n", unequal ? "rated" : unsorted ? "unrated" : "maybe");
  return 0;
}
