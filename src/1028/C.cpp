#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 132674
#define MAXXY 1000000000

using namespace std;

struct Rect {
  int x1, y1, x2, y2;
  int x1n, y1n, x2n, y2n;

  Rect() = default;
  Rect(int _x1, int _y1, int _x2, int _y2):
    x1(_x1), y1(_y1), x2(_x2), y2(_y2), x1n(-1), y1n(-1), x2n(-1), y2n(-1) {}

  Rect intersect(Rect& o) {
    Rect res(max(x1, o.x1), max(y1, o.y1), min(x2, o.x2), min(y2, o.y2));
    res.x1n = x1 > o.x1 ? x1n : o.x1n;
    res.y1n = y1 > o.y1 ? y1n : o.y1n;
    res.x2n = x2 < o.x2 ? x2n : o.x2n;
    res.y2n = y2 < o.y2 ? y2n : o.y2n;
    return res;
  }

  bool isEmpty() {
    return x1 > x2 || y1 > y2;
  }
};

int n;
Rect rs[MAXN];

Rect intersectAllExcept(int k) {
  Rect res(-MAXXY, -MAXXY, MAXXY, MAXXY);
  for(int i = 0; i < n; i++) {
    if(i == k) continue;
    res = res.intersect(rs[i]);
  }
  return res;
}

Rect intersectAllExceptOneOf(int k1, int k2) {
  Rect res = intersectAllExcept(k1);
  return res.isEmpty() ? intersectAllExcept(k2) : res;
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d %d\n", &rs[i].x1, &rs[i].y1, &rs[i].x2, &rs[i].y2);
    rs[i].x1n = rs[i].y1n = rs[i].x2n = rs[i].y2n = i;
  }

  Rect curr(-MAXXY, -MAXXY, MAXXY, MAXXY);
  for(int i = 0; i < n; i++) {
    Rect next = curr.intersect(rs[i]);
    if(next.x1 > next.x2) {
      curr = intersectAllExceptOneOf(next.x1n, next.x2n);
      break;
    }
    if(next.y1 > next.y2) {
      curr = intersectAllExceptOneOf(next.y1n, next.y2n);
      break;
    }
    curr = next;
  }
  printf("%d %d\n", curr.x1, curr.y1);
  return 0;
}
