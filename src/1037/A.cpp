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

int main() {
  int n; scanf("%d\n", &n);
  int packets = 0;
  while(n > 0) {
    packets++;
    n /= 2;
  }
  printf("%d\n", packets);
  return 0;
}
