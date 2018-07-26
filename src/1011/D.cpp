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

#define MAXN 30
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

bool broken[MAXN];

int ask(int y) {
  printf("%d\n", y);
  fflush(stdout);

  int ans; scanf("%d", &ans);
  if(ans == 0 || ans == -2) exit(0);
  return ans;
}

int main() {
  int m, n; scanf("%d %d", &m, &n);

  for(int i = 0; i < n; i++) {
    broken[i] = ask(1) == -1;
  }

  int lowY = 1, hiY = m, tries = 0;
  while(lowY < hiY) {
    int midY = (lowY + hiY) / 2;

    int resT = ask(midY);
    if(broken[tries % n]) resT = -resT;
    tries++;

    if(resT == 1) lowY = midY + 1;
    else hiY = midY - 1;
  }
  ask(lowY);
  return 0;
}
