#include <algorithm>
#include <cstdio>

#define MAXB 40

using namespace std;

typedef long long ll;

int bases[MAXB + 1], tails[MAXB + 1];
int minLen, maxLen;

int log2(ll n) {
  if(n <= 1) return (int) n;
  return 1 + log2(n >> 1);
}

bool calc() {
  for(int i = 2; i <= MAXB; i++) {
    if(bases[i] > bases[i - 1]) {
      tails[i - 1] += bases[i] - bases[i - 1];
      bases[i] = bases[i - 1];
    }
  }

  for(int i = MAXB; i > 0; i--) {
    if(!tails[i]) continue;
    if(bases[i] < tails[i]) return false;

    for(int j = 1; j <= i; j++) {
      bases[j] -= tails[i];
    }
    minLen += tails[i];

    for(int j = i + 1; tails[i] > 0 && j <= MAXB; j++) {
      tails[i] = min(bases[j], tails[i]);
      bases[j] -= tails[i];
    }
  }

  maxLen = minLen + bases[1];

  int tailFree = bases[1], curr = 1;
  while(true) {
    while(curr < MAXB && bases[curr + 1] == bases[curr]) curr++;

    if(tailFree - 1 >= curr) { tailFree -= curr + 1; bases[curr]--; }
    else break;
  }
  minLen += bases[curr];
  return true;
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    ll ai; scanf("%lld", &ai);
    int order = log2(ai);
    if(ai == 1LL << (order - 1)) bases[order]++;
    else tails[order]++;
  }

  if(!calc()) {
    printf("-1\n");
  } else {
    for(int i = minLen; i <= maxLen; i++)
      printf("%d ", i);
    printf("\n");
  }
  return 0;
}
