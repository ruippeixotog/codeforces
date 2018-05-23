#include <cstdio>

using namespace std;

int main() {
  int n; scanf("%d\n", &n);
  int n0 = 0, n1 = 0;
  for(int i = 0; i < n; i++) {
    char ch; scanf("%c", &ch);
    (ch == '0' ? n0 : n1)++;
  }
  if(n1 > 0) printf("1");
  while(n0--) printf("0");
  printf("\n");
  return 0;
}
