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

#define MAXN 50
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

char s[MAXN + 1];

int main() {
  int n, k; scanf("%d %d\n", &n, &k);
  scanf("%s\n", s);

  sort(s, s + n);

  int cnt = 0, w = 0, last = -1;
  for(int i = 0; i < n && cnt < k; i++) {
    if(last == -1 || s[i] - s[last] >= 2) {
      cnt++; w += s[i] - 'a' + 1; last = i;
    }
  }
  printf("%d\n", cnt == k ? w : -1);
  return 0;
}
