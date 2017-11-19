#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string str; cin >> str;

  int cnt = 0;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] != 'Q') continue;
    for(int j = i + 1; j < str.size(); j++) {
      if(str[j] != 'A') continue;
      for(int k = j + 1; k < str.size(); k++) {
        if(str[k] != 'Q') continue;
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
