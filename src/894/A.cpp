#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  string str; cin >> str;

  int cnt = 0;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] != 'Q') continue;
    for(int j = i + 1; j < str.size(); j++) {
      if(str[j] != 'A') continue;
      for(int k = j + 1; k < str.size(); k++) {
        if(str[k] != 'Q') continue;
        cnt += 1;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
