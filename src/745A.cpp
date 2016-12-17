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

int x[MAXN], y[MAXN];

set<string> distinct;

int main() {
  string str; cin >> str;
  for(int i = 0; i < str.length(); i++) {
    str = string(1, str[str.length() - 1]) + str.substr(0, str.length() - 1);
    distinct.insert(str);
  }
  printf("%d\n", (int) distinct.size());
  return 0;
}
