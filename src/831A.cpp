#include <cstdio>

#define MAXN 100

using namespace std;

int a[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int i = 0;
  while(i < n - 1 && a[i] < a[i + 1]) i++;
  while(i < n - 1 && a[i] == a[i + 1]) i++;
  while(i < n - 1 && a[i] > a[i + 1]) i++;

  printf("%s\n", i == n - 1 ? "YES" : "NO");
  return 0;
}
