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
#define MAXL 20000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

char dir[10];

int main() {
  int n; scanf("%d\n", &n);

  int lat = 0; bool valid = true;
  for(int i = 0; i < n; i++) {
    int v; scanf("%d %s\n", &v, dir);

    if(lat == 0 && dir[0] != 'S') { valid = false; break; }
    if(lat == MAXL && dir[0] != 'N') { valid = false; break; }

    if(dir[0] == 'N') {
      lat -= v;
      if(lat < 0) { valid = false; break; }
    }
    else if(dir[0] == 'S') {
      lat += v;
      if(lat > MAXL) { valid = false; break; }
    }
    cerr << lat << endl;
  }
  printf("%s\n", valid && lat == 0 ? "YES" : "NO");
  return 0;
}
