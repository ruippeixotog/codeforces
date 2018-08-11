#include <cstdio>
#include <cstring>

#define MAXN 1000

int p[MAXN];

bool visited[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  for(int i = 0; i < n; i++) {
    memset(visited, false, sizeof(visited));
    int curr = i;
    while(!visited[curr]) {
      visited[curr] = true;
      curr = p[curr] - 1;
    }
    printf("%d ", curr + 1);
  }
  return 0;
}
