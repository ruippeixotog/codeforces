#include <cstdio>

int ask(int y) {
  printf("? %d\n", y + 1);
  fflush(stdout);

  int ans; scanf("%d", &ans);
  return ans;
}

int askDiff(int y, int n) {
  return ask(y) - ask((y + n / 2) % n);
}

int main() {
  int n; scanf("%d", &n);

  int res = -1;
  if(n % 4 == 0) {
    int diff0 = askDiff(0, n);
    if(diff0 == 0) res = 1;
    else {
      int first = diff0 < 0 ? 1 : n / 2 + 1;
      int last = diff0 < 0 ? n / 2 - 1 : n - 1;

      while(first <= last) {
        int mid = (first + last) / 2;
        int diff = askDiff(mid, n);

        if(diff == 0) { res = mid + 1; break; }
        if(diff < 0) first = mid + 1;
        else last = mid - 1;
      }
    }
  }
  printf("! %d\n", res);
  return 0;
}
