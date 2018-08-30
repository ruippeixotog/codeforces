#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 300000
#define MAXD 30

using namespace std;

vector<int> toBinDigits(int k, int digits = MAXD) {
  vector<int> res;
  while(digits--) {
    res.push_back(k % 2);
    k /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}

struct Trie {
  int count;
  Trie* children[2];

  Trie(): count(0), children {nullptr, nullptr} {}

  void add(vector<int>& arr, int k = 0) {
    count++;
    if(k == arr.size()) return;
    if(!children[arr[k]]) {
      children[arr[k]] = new Trie();
    }
    children[arr[k]]->add(arr, k + 1);
  }

  int popBest(vector<int>& arr, int k = 0, int acc = 0) {
    count--;
    if(k == arr.size()) return acc;
    int digit = children[arr[k]] ? arr[k] : 1 - arr[k];
    int res = children[digit]->popBest(arr, k + 1, (acc << 1) + digit);
    if(children[digit]->count == 0) {
      delete children[digit];
      children[digit] = nullptr;
    }
    return res;
  }
};

int a[MAXN];
Trie p;

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) {
    int pi; scanf("%d", &pi);
    vector<int> pid = toBinDigits(pi);
    p.add(pid);
  }

  for(int i = 0; i < n; i++) {
    vector<int> aid = toBinDigits(a[i]);
    printf("%d ", a[i] ^ p.popBest(aid));
  }
  printf("\n");
  return 0;
}
