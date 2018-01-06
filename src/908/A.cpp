#include <cstdio>
#include <string>

#define MAXN 50

using namespace std;

string vowels = "aeiou", odd = "13579";

char s[MAXN + 1];

int main() {
  scanf("%s\n", s);

  int cnt = 0;
  for(int i = 0; s[i]; i++) {
    cnt += (int) odd.find(s[i]) >= 0 || (int) vowels.find(s[i]) >= 0;
  }
  printf("%d\n", cnt);
  return 0;
}
