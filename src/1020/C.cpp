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
#include <numeric>

#define MAXN 3000
#define MAXM 3000
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
int p[MAXN], c[MAXN];

int order[MAXN], votes[MAXM];
int currVotes[MAXN]; bool bought[MAXN];

ll calcCost(int numVotes) {
  memcpy(currVotes, votes, sizeof(votes));
  memset(bought, false, sizeof(bought));

  ll cost = 0;
  for(int i = 0; i < n && currVotes[0] < numVotes; i++) {
    if(currVotes[p[order[i]]] >= numVotes) {
      cost += c[order[i]];
      currVotes[0]++;
      currVotes[p[order[i]]]--;
      bought[order[i]] = true;
    }
  }

  for(int i = 0; i < n && currVotes[0] < numVotes; i++) {
    if(p[order[i]] != 0 && !bought[order[i]]) {
      cost += c[order[i]];
      currVotes[0]++;
      currVotes[p[order[i]]]--;
      bought[order[i]] = true;
    }
  }

  for(int i = 1; i < m; i++) {
    if(currVotes[i] >= numVotes) {
      cerr << "cost for " << numVotes << ": fail0" << endl;
      return INF;
    }
  }
  if(currVotes[0] < numVotes) {
    cerr << "cost for " << numVotes << ": fail1" << endl;
  } else {
    cerr << "cost for " << numVotes << ": " << cost << endl;
  }
  return currVotes[0] < numVotes ? INF : cost;
}

int main() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d %d\n", &p[i], &c[i]);
    p[i]--;
  }

  memset(votes, 0, sizeof(votes));
  for(int i = 0; i < n; i++) {
    votes[p[i]]++;
  }

  iota(order, order + n, 0);
  sort(order, order + n, [](int i1, int i2) {
    return c[i1] < c[i2];
  });

  ll bestCost = INF;
  for(int numVotes = 0; numVotes <= n / 2 + 1; numVotes++) {
    bestCost = min(bestCost, calcCost(numVotes));
  }

//  int minV = 0, maxV = n / 2 + 1;
//  while(minV < maxV) {
//    int midV = (minV + maxV) / 2;
//    if(calcCost(midV) == -1) {
//      minV = midV + 1;
//    } else {
//      maxV = midV;
//    }
//  }
  printf("%lld\n", bestCost);
  return 0;
}
