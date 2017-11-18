#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 1000

using namespace std;

int n;

int mins[MAXN];

void ask(vector<int>& q) {
  printf("%d\n", (int) q.size());
  for(int e: q) printf("%d ", e);
  printf("\n"); fflush(stdout);

  q.resize(n);
  for(int i = 0; i < n; i++) scanf("%d", &q[i]);
}

int main() {
  scanf("%d", &n);
  memset(mins, 0x3f, sizeof(mins));

  int div = 1;
  while((div * 2) < n) div *= 2;

  for(; div > 0; div /= 2) {
    vector<int> q1, q2;
    for(int i = 0; i < n; i++) {
      (i / div % 2 ? q2 : q1).push_back(i + 1);
    }
    ask(q1);
    ask(q2);
    for(int i = 0; i < n; i++) {
      mins[i] = min(mins[i], (i / div % 2 ? q1 : q2)[i]);
    }
  }
  printf("-1\n");
  for(int i = 0; i < n; i++) printf("%d ", mins[i]);
  printf("\n"); fflush(stdout);
  return 0;
}
