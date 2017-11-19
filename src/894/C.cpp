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

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int m; scanf("%d\n", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }

  bool possible = true;
  for(int i = m - 1; i >= 0; i--) {
    if(gcd(a[i], a[0]) != a[0]) { possible = false; break; }
  }

  if(possible) {
    printf("%d\n", m * 2 - 1);
    printf("%d", a[0]);
    for(int i = 1; i < m; i++) printf(" %d %d", a[i], a[0]);
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}

//set<int> a;
//
//int gcd(int a, int b) {
//  return b == 0 ? a : gcd(b, a % b);
//}
//
//int main() {
//  int m; scanf("%d\n", &m);
//  for(int i = 0; i < m; i++) {
//    int ai; scanf("%d", &ai); a.insert(ai);
//  }
//
//  bool possible = true; int last = *a.rbegin();
//  for(auto it = a.rbegin(); it != a.rend(); it++) {
//    if(!a.count(gcd(*it, last))) { possible = false; break; }
//    last = *it;
//  }
//
//  if(possible) {
//    for(int ai : a) printf("%d ", ai);
//    printf("\n");
//  } else {
//    printf("-1\n");
//  }
//  return 0;
//}
