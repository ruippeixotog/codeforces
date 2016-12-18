#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

set<string> distinct;

int main() {
  string str; cin >> str;
  for(int i = 0; i < str.length(); i++) {
    str = str.substr(1) + str.substr(0, 1);
    distinct.insert(str);
  }
  printf("%d\n", (int) distinct.size());
  return 0;
}
