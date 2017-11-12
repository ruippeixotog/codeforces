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

int t[MAXN];

bool available[MAXN];

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &t[i]);

  available[0] = true;
  int cnt = 1;
  for(int i = 0; i < n; i++) {
    if(available[t[i]]) available[t[i]] = false;
    else cnt++;
    available[i + 1] = true;
  }
  printf("%d\n", cnt);
  return 0;
}
