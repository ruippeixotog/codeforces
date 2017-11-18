#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n; scanf("%d\n", &n);
  string str; getline(cin, str);

  int idx = 0, idx2 = 0;
  while((idx2 = str.find("ogo", idx)) >= 0) {
    for(int i = idx; i < idx2; i++) {
      printf("%c", str[i]);
    }
    printf("***");

    idx2 += 3;
    while(idx2 + 1 < n && str[idx2] == 'g' && str[idx2 + 1] == 'o') {
      idx2 += 2;
    }
    idx = idx2;
  }
  for(int i = idx; i < n; i++) {
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
