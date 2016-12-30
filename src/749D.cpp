#include <algorithm>
#include <cstdio>
#include <utility>
#include <set>
#include <vector>

#define MAXN 200000

using namespace std;

vector<int> bids[MAXN];

int maxBids[MAXN];
vector<pair<int, int>> sortedBids;

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    int a, b; scanf("%d %d\n", &a, &b);
    bids[a - 1].push_back(b);
    maxBids[a - 1] = max(maxBids[a - 1], b);
  }

  for(int i = 0; i < n; i++) {
    if(maxBids[i] > 0) sortedBids.push_back({ maxBids[i], i });
  }
  int np = (int) sortedBids.size();
  sort(sortedBids.rbegin(), sortedBids.rend());

  int q; scanf("%d\n", &q);
  while(q--) {
    int k; scanf("%d\n", &k);
    set<int> l;
    while(k--) {
      int li; scanf("%d\n", &li);
      l.insert(li - 1);
    }

    int i = 0;
    while(i < np && l.count(sortedBids[i].second)) i++;
    int j = i + 1;
    while(j < np && l.count(sortedBids[j].second)) j++;

    if(i == np) printf("0 0\n");
    else {
      int winner = sortedBids[i].second;
      int secondBid = j >= np ? 0 : sortedBids[j].first;
      int winningBid = *upper_bound(
        bids[winner].begin(), bids[winner].end(), secondBid);

      printf("%d %d\n", winner + 1, winningBid);
    }
  }
  return 0;
}
