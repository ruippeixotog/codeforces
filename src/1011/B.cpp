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

#define MAXN 100
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

int main() {
  int n, m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < m; i++)
    scanf("%d", &a[i]);

  sort(a, a + m);

  int lowT = 0, hiT = m / n;
  while(lowT < hiT) {
    int midT = (lowT + hiT + 1) / 2;
//    cerr << lowT << " " << hiT << endl;
//    cerr << midT << endl;

    int idx = 0;
    bool success = true;
    for(int i = 0; i < n; i++) {
      int taken = 0, curr = -1;
      while(taken < midT && idx < m) {
        taken = curr == -1 || curr == a[idx] ? taken + 1 : 1;
        curr = a[idx];
        idx++;
      }
      if(taken < midT) {
        success = false;
        break;
      }
    }

    if(success) lowT = midT;
    else hiT = midT - 1;
  }
  printf("%d\n", lowT);
  return 0;
}
