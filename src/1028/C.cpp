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

#define MAXN 132674
#define MAXX 1000000001

using namespace std;

typedef long long ll;
typedef long double ld;

struct Rect {
  int x1, y1, x2, y2;
  int x1n, y1n, x2n, y2n;

  Rect() {}
  Rect(int _x1, int _y1, int _x2, int _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

  Rect intersect(Rect& o) {
    Rect res;
    res.x1 = max(x1, o.x1);
    res.x1n = x1 > o.x1 ? x1n : o.x1n;
    res.y1 = max(y1, o.y1);
    res.y1n = y1 > o.y1 ? y1n : o.y1n;
    res.x2 = min(x2, o.x2);
    res.x2n = x2 < o.x2 ? x2n : o.x2n;
    res.y2 = min(y2, o.y2);
    res.y2n = y2 < o.y2 ? y2n : o.y2n;
    return res;
  }

  bool isEmpty() {
    return x1 > x2 || y1 > y2;
  }

  void print() {
    fprintf(stderr, "%d(%d), %d(%d), %d(%d), %d(%d)\n", x1, x1n, y1, y1n, x2, x2n, y2, y2n);
  }
};

int n;
Rect rs[MAXN];

Rect intersectAllExcept(int k) {
  Rect curr(-MAXX, -MAXX, MAXX, MAXX);
  for(int i = 0; i < n; i++) {
    if(i == k) continue;
    curr = curr.intersect(rs[i]);
  }
  return curr;
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d %d\n", &rs[i].x1, &rs[i].y1, &rs[i].x2, &rs[i].y2);
    rs[i].x1n = rs[i].y1n = rs[i].x2n = rs[i].y2n = i;
//    rs[i].print();
  }

  Rect curr(-MAXX, -MAXX, MAXX, MAXX);
  for(int i = 0; i < n; i++) {
    Rect next = curr.intersect(rs[i]);

    if(next.isEmpty()) {
//      cerr << "empty intersect at " << i << endl;
//      next.print();

      if(next.x1 > next.x2) {
        curr = intersectAllExcept(next.x1n);
        if(curr.isEmpty()) {
          curr = intersectAllExcept(next.x2n);
        }
        if(curr.isEmpty()) {
          throw "fail x1x2";
        }
      }
      else {
        curr = intersectAllExcept(next.y1n);
        if(curr.isEmpty()) {
          curr = intersectAllExcept(next.y2n);
        }
        if(curr.isEmpty()) {
          throw "fail y1y2";
        }
      }
      break;
    }
    curr = next;
  }
  printf("%d %d\n", curr.x1, curr.y1);
  return 0;
}
