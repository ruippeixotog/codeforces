#include <algorithm>
#include <cstdio>

#define MAXN 200000
#define INF 1000000000

using namespace std;

int a[MAXN];

int hist[MAXN];

int main() {
  int n, s; scanf("%d %d\n", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d\n", &a[i]);
    hist[a[i]]++;
  }

  int mistakes = 0, free = 0, moves = 0;

  if(a[s - 1] != 0) { hist[a[s - 1]]--; mistakes++; }
  else { hist[0]--; }

  if(hist[0] > 0) {
    mistakes += hist[0];
    free += hist[0];
  }

  int processed = hist[0] + 1;
  int minMistakes = INF;

  for(int i = 1; i < n; i++) {
    if(hist[i] > 0) processed += hist[i];
    else if(free > 0) free--;
    else {
      minMistakes = min(minMistakes, mistakes + max(0, n - processed - moves));
      moves++;
      mistakes++;
    }
  }
  minMistakes = min(minMistakes, mistakes);

  printf("%d\n", minMistakes);
  return 0;
}
