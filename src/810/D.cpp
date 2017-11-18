#include <cstdio>

char op[4];

bool ask(int a, int b) {
  printf("1 %d %d\n", a, b); fflush(stdout);
  scanf("%s", op);
  return op[0] == 'T';
}

int findBetween(int min, int max) {
  if(min == max) return min;
  int quarter = (max - min + 1) / 4;
  bool res = ask(min + quarter, max - quarter);

  int cut = (max - min + 2) / 2;
  return res ?
         findBetween(min, min + cut - 1) :
         findBetween(min + cut, max);
}

int findSecondBetween(int min, int max, int first) {
  if(first == min) return findBetween(min + 1, max);
  if(first == max) return findBetween(min, max - 1);

  int left = findBetween(min, first - 1);
  if(left != first - 1) return left;
  int right = findBetween(first + 1, max);
  if(right != first + 1) return right;

  return ask(first - 1, first + 1) ? first - 1 : first + 1;
}

int main() {
  int n, k; scanf("%d %d", &n, &k);

  int first = findBetween(1, n);
  int second = findSecondBetween(1, n, first);

  printf("2 %d %d\n", first, second);
  fflush(stdout);
  return 0;
}
