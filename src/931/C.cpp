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

int x[MAXN];

int hist[3];
vector<int> sol;

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  int low = INF, hi = -INF;
  for(int i = 0; i < n; i++) {
    low = min(low, x[i]); hi = max(hi, x[i]);
  }

  int minEq = 0;

  if(hi - low < 2) {
    minEq = n;
    for(int i = 0; i < n; i++) {
      sol.push_back(x[i]);
    }

  } else {
    for(int i = 0; i < n; i++) {
      hist[x[i] - low]++;
    }
//    cerr << hist[0] << " " << hist[1] << " " << hist[2] << endl;

    for(; hist[0] > hist[2]; hist[0]--) {
      sol.push_back(low);
      minEq++;
    }
    for(; hist[2] > hist[0]; hist[2]--) {
      sol.push_back(low + 2);
      minEq++;
    }
    if(hist[1] % 2 == 1) {
      sol.push_back(low + 1);
      hist[1]--; minEq++;
    }
    if(hist[1] > hist[0] * 2) {
      minEq += hist[0] * 2;
      for(int i = 0; i < hist[0] + hist[1] / 2; i++) {
        sol.push_back(low);
        sol.push_back(low + 2);
      }
    } else {
      minEq += hist[1];
      for(int i = 0; i < hist[1] + hist[0] * 2; i++) {
        sol.push_back(low + 1);
      }
    }
  }

  printf("%d\n", minEq);
  for(int si : sol) {
    printf("%d ", si);
  }
  printf("\n");
  return 0;
}
