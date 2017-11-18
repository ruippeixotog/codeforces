#include <cstdio>

using namespace std;

int main() {
  int n; scanf("%d\n", &n);

  int a = 0, d = 0;
  while(n--) {
    char ch; scanf("%c", &ch);
    if(ch == 'A') a++;
    else d++;
  }

  if(a == d) printf("Friendship\n");
  else if(a > d) printf("Anton\n");
  else printf("Danik\n");
}
