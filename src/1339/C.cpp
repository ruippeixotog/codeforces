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

int a[MAXN];

int getSecond(int k) {
  int cnt = 0;
  while(k > 0) {
    cnt++;
    k /= 2;
  }
  return cnt;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    int curr = a[0];
    int maxSeconds = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] < curr) {
        maxSeconds = max(maxSeconds, getSecond(curr - a[i]));
      } else if(a[i] > curr) {
        curr = a[i];
      }
    }
    printf("%d\n", maxSeconds);
  }
  return 0;
}
