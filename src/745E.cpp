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

#define MAXN 16
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
char c[MAXN]; int r[MAXN], b[MAXN];

map<int, int> dpR[1 << MAXN];
map<int, int> dpB[1 << MAXN];

void tryMin(int st, int rTokens, int bTokens, int cand) {
  map<int, int>& dp = bTokens > 0 ? dpB[st] : dpR[st];
  int tokens = bTokens > 0 ? bTokens : rTokens;

  if(dp.count(tokens)) dp[tokens] = min(dp[tokens], cand);
  else dp[tokens] = cand;
}

void calc(int st, int i, int curr, int target) {
  if(curr == target) {
//    cerr << "expanding " << bitset<8>(st) << endl;
    int rCards = 0, bCards = 0;
    for(int j = 0; j < n; j++) {
      if(st & (1 << j)) (c[j] == 'R' ? rCards : bCards)++;
    }

//    for(auto entry: dpR[st]) {
//      cerr << "- red " << entry.first << ": " << entry.second << endl;
//    }
//    for(auto entry: dpB[st]) {
//      cerr << "- blue " << entry.first << ": " << entry.second << endl;
//    }

    for(int j = 0; j < n; j++) {
      if(st & (1 << j)) continue;
      int rCost = max(0, r[j] - rCards), bCost = max(0, b[j] - bCards);

      for(auto rTokens: dpR[st]) {
        int buys = max(rCost - rTokens.first, bCost);
        tryMin(st | (1 << j),
               rTokens.first + buys - rCost,
               buys - bCost,
               rTokens.second + buys + 1);
      }

      for(auto bTokens: dpB[st]) {
        int buys = max(rCost, bCost - bTokens.first);
        tryMin(st | (1 << j),
               buys - rCost,
               bTokens.first + buys - bCost,
               bTokens.second + buys + 1);
      }
    }
    return;
  }

  if(i == n) return;
  calc(st, i + 1, curr, target);
  calc(st | (1 << i), i + 1, curr + 1, target);
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%c %d %d\n", &c[i], &r[i], &b[i]);
  }

  dpR[0][0] = 0;
  for(int i = 0; i < n; i++) {
    calc(0, 0, 0, i);
  }

  int best = INF;
  for(auto entry: dpR[(1 << n) - 1]) {
//    cerr << "red " << entry.first << ": " << entry.second << endl;
    best = min(best, entry.second);
  }
  for(auto entry: dpB[(1 << n) - 1]) {
//    cerr << "blue " << entry.first << ": " << entry.second << endl;
    best = min(best, entry.second);
  }

  printf("%d\n", best);
  return 0;
}
