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

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int x[MAXN], y[MAXN];

int main() {
  int m, d; scanf("%d %d\n", &m, &d);

  int weeks = (monthDays[m - 1] + d - 1 + 6) / 7;
  printf("%d\n", weeks);
  return 0;
}
