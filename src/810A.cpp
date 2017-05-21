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

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a); sum += a;
  }
  int nh = n;
  while(sum / (ld) nh < k - 0.5) {
    sum += k; nh++;
  }
  printf("%d\n", nh - n);
  return 0;
}
