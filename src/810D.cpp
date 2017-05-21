#include <algorithm>
#include <cmath>
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

int x[MAXN], y[MAXN];

char op[4];

int opCount = 0;

//bool ask(int a, int b) {
//  printf("1 %d %d\n", a, b); fflush(stdout);
//  opCount++;
//  scanf("%s", op);
//  return op[0] == 'T';
//}

int targetA = 1, targetB = 2;
bool ask(int a, int b) {
  int distA = min(abs(a - targetA), abs(a - targetB));
  int distB = min(abs(b - targetA), abs(b - targetB));
  cerr << a << " " << b << "? " << (distA <= distB) << endl;
  return distA <= distB;
}

int findBetween(int min, int max) {
  cerr << "find: " << min << " " << max << endl;
  if(min == max) return min;
  else if(max - min <= 2) {
    bool res = ask(min, max);
    return res ? (max - min == 2 ? findBetween(min, min + 1) : min) : max;
  }

  int quarter = (max - min + 1) / 4;
  bool res = ask(min + quarter, max - quarter);

  return res ?
         findBetween(min, min + quarter * 2) :
         findBetween(std::max(min + quarter * 2 + 1, max - quarter * 2), max);
}

int findSecondBetween(int min, int max, int first) {
  if(abs(min - first) < abs(max - first)) {
    int tmp = findBetween((max + min + 1) / 2, max);
    if(tmp != (max + min + 1) / 2) return tmp;
    else return findSecondBetween(min, (max + min + 1) / 2, first);
  } else {
    int tmp = findBetween(min, (max + min) / 2);
    if(tmp != (max + min) / 2) return tmp;
    else return findSecondBetween((max + min) / 2, max, first);
  }
}

int main() {
  int n, k; scanf("%d %d\n", &n, &k);

  int first = findBetween(1, n);
  cerr << "first is " << first << endl;
  int second = findSecondBetween(1, n, first);

  cerr << "ops: " << opCount << endl;

  printf("2 %d %d\n", first, second);
  fflush(stdout);
  return 0;
}
