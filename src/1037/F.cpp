#include <algorithm>
#include <cstdio>
#include <stack>

#define MAXN 1000000
#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

int n, k;
int a[MAXN];

struct Entry {
  int number, init, times;
  Entry(int nm, int in, int tm): number(nm), init(in), times(tm) {}
};

ll countDiags(ll width, ll height, ll phase) {
  if(height == 1) {
    return (width + phase) / (k - 1);
  }
  ll hMid = height / 2;
  return countDiags(width, hMid, phase) +
         countDiags(width, height - hMid, (phase + hMid) % (k - 1));
}

ll process(Entry& e, int currIdx) {
  ll width = currIdx - e.init, height = e.times;
  if(width < height) swap(width, height);
  return mmul(e.number, (countDiags(width, height, k - 2) - 1) % MOD);
}

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  ll res = 0;
  stack<Entry> q;
  for(int i = 0; i < n; i++) {
    int toFill = 1;
    while(!q.empty() && q.top().number < a[i]) {
      Entry& e = q.top();
      res = madd(res, process(e, i));
      toFill += e.times;
      q.pop();
    }
    q.push(Entry(a[i], i, toFill));
  }
  while(!q.empty()) {
    res = madd(res, process(q.top(), n));
    q.pop();
  }
  printf("%lld\n", res);
  return 0;
}
