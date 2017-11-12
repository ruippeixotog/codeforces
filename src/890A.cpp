#include <cstdio>

int a[6];

bool check(int sum) {
  for(int i = 0; i < 6; i++) {
    for(int j = i + 1; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        if(a[i] + a[j] + a[k] == sum) return true;
      }
    }
  }
  return false;
}

int main() {
  for (int &ai : a)
    scanf("%d", &ai);

  int sum = 0;
  for (int ai : a) sum += ai;

  printf("%s\n", sum % 2 == 0 && check(sum / 2) ? "YES" : "NO");
  return 0;
}
