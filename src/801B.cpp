#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string x, y; cin >> x >> y;

  bool impossible = false;
  for(int i = 0; i < x.size(); i++) {
    if(x[i] < y[i]) { impossible = true; break; }
  }
  printf("%s\n", impossible ? "-1" : y.c_str());
  return 0;
}
