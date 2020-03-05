#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, x; scanf("%d %d\n", &n, &x);
    string s; getline(cin, s);

    int curr = 0;
    vector<int> balances;
    for(char ch : s) {
      balances.push_back(curr);
      curr += ch == '0' ? 1 : -1;
    }

    int cnt = 0;
    for(int balance : balances) {
      if(curr == 0 && balance == x) {
        cnt = -1;
      } else if(curr != 0) {
        cnt += (x - balance) % curr == 0 && (x - balance) / curr >= 0;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
