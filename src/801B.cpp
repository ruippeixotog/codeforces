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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  string x, y; cin >> x >> y;

  bool impossible = false;
  for(int i = 0; i < x.size(); i++) {
    if(x[i] < y[i]) { impossible = true; break; }
  }
  printf("%s\n", impossible ? "-1" : y.c_str());
  return 0;
}
