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

int a[6];

bool check(int sum) {
  for(int i = 0; i < 6; i++) {
    for(int j = i + 1; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        if(a[i] + a[j] + a[k] == sum) return true;
      }
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < 6; i++)
    scanf("%d", &a[i]);

  int sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += a[i];
  }

  printf("%s\n", sum % 2 == 0 && check(sum / 2) ? "YES" : "NO");
  return 0;
}
