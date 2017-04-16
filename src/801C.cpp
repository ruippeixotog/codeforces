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

#define MAXN 100000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

tuple<ld, ll, ll> devices[MAXN];

//ld epsilon = 1e-10;
//
//bool gte(ld a, ld b) {
//  return (a + epsilon) >= b;
//}

int main() {
  int n, p; scanf("%d %d\n", &n, &p);
  for(int i = 0; i < n; i++) {
    int a, b; scanf("%d %d\n", &a, &b);
    devices[i] = make_tuple(b / (ld) a, (ll) a, (ll) b);
  }
  sort(devices, devices + n);

  int i = 0;
  bool infinite = false;
  while(true) {
    if(i == n - 1) {
      //      cerr << "last" << endl;
      if(p >= get<1>(devices[i])) {
        infinite = true;
      } else {
        get<1>(devices[i]) -= p;
      }
      // pLeft -= provided;
      break;
    } else {
      ld needed = get<1>(devices[i]) - get<1>(devices[i + 1]) / (ld) get<2>(devices[i + 1]);
      if(needed >= p) {
//        cerr << "needed too much" << endl;
        get<1>(devices[i]) -= p;
        // pLeft = 0.0;
        break;
      } else {
//        cerr << "provide" << endl;
        get<1>(devices[i + 1]) += get<1>(devices[i]); // - needed;
        get<2>(devices[i + 1]) += get<2>(devices[i]);
        // pLeft -= needed;
        i++;
      }
    }
  }

  if(infinite) printf("-1\n");
  else printf("%.9f\n", (double) (get<2>(devices[i]) / (ld) get<1>(devices[i])));
  return 0;
}
