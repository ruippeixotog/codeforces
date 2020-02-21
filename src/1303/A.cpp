#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; getline(cin, s);
  
    bool foundOne = false;
    int totalZeros = 0, currZeros = 0;
    for(char ch : s) {
      if(ch == '0' && foundOne) {
        currZeros++;
      } else if(ch == '1') {
        foundOne = true;
        totalZeros += currZeros;
        currZeros = 0;
      }
    }
    printf("%d\n", totalZeros);
  }
  return 0;
}
