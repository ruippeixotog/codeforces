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
#include <cassert>

#define MAXN 1000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n, L[MAXN];

map<int, int> dist[MAXN];

void calcDist(int k) {
  dist[k][0] = 1;
//  cerr << "at: " << k << endl;

  int left = k * 2 + 1, right = left + 1;
//  cerr << "left: " << left << ", right = " << right << endl;

  if(left < n) {
    calcDist(left);
    for(auto it : dist[left]) {
      dist[k][L[left - 1] + it.first] += it.second;
//      fprintf(stderr, "dist[%d][%d] += %d\n", k, L[left - 1] + it.first, it.second);
    }

//    for(int i = 0; dist[left][i] > 0; i++) {
//      dist[k][i + 1] += dist[left][i];
//    }
  }
  if(right < n) {
    calcDist(right);
    for(auto it : dist[right]) {
      dist[k][L[right - 1] + it.first] += it.second;
//      fprintf(stderr, "dist[%d][%d] += %d\n", k, L[right - 1] + it.first, it.second);
    }

//    for(int i = 0; dist[right][i] > 0; i++) {
//      dist[k][i + 1] += dist[right][i];
//    }
  }
}

int query(int a, int h, int prev) {
  if(h <= 0) return 0;
  cerr << "q: " << a << " " << h << " " << prev << endl;

  int happiness = 0;
  if(prev == -1) {
    for(auto it : dist[a]) {
      if(it.first >= h) break;
      happiness += it.second * (h - it.first);
    }
  } else if(prev == a * 2 + 1) {
    happiness += h + query(a * 2 + 2, h - L[a * 2 + 2 - 1], -1);
  } else {
    happiness += h + query(a * 2 + 1, h - L[a * 2 + 1 - 1], -1);
  }

//  for(auto it : dist[a]) {
//    if(it.first >= h) break;
//
//    if(prev == -1 || it.first < L[prev - 1]) {
//      happiness += it.second * (h - it.first);
//    } else {
//      happiness += (it.second - dist[prev][it.first - L[prev - 1]]) * (h - it.first);
////      fprintf(stderr, "dist[%d][%d] - dist[%d][%d]\n", a, i, prev, i - L[a - 1]);
//    }
//  }

  int parent = (a - 1) / 2;
  if(parent != a) {
    happiness += query(parent, h - L[a - 1], a);
  }
  return happiness;
}

int main() {
  int m; scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n - 1; i++)
    scanf("%d", &L[i]);

  calcDist(0);
//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < 21; j++) {
//      cerr << dist[i][j] << " ";
//    }
//    cerr << endl;
//  }

  for(int i = 0; i < m; i++) {
    int a, h; scanf("%d %d\n", &a, &h);
//    cerr << "query: " << a << " " << h << endl;
    printf("%d\n", query(a - 1, h, -1));
  }
  return 0;
}
