#include <cstdio>

#define MAXN 100000

char s[MAXN + 1];

char res[MAXN + 1];

int main() {

  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    scanf("%s\n", s);

    int carry = 0;
    for(int i = n - 1; i >= 0; i--) {
      int dSum = i == n - 1 || s[0] == '9' ? 1 : 0;
      int dArg = s[i] - '0';

      int dRes = dSum - dArg - carry;
      if((carry = dRes < 0)) {
        dRes += 10;
      }
      res[i] = dRes + '0';
    }
    res[n] = '\0';
    printf("%s\n", res);
  }
  return 0;
}
