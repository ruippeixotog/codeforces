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
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> children[MAXN];
int alias[MAXN];

//bool terminated[MAXN];
queue<int> fruits[MAXN];

void simplify(int k) {
//  for(int adj : children[k]) {
//    simplify(adj);
//  }
  if(children[k].size() == 1) {
    int adj = children[k][0];
    children[k].pop_back();
    alias[adj] = k;

    for(int dadj : children[adj]) {
      children[k].push_back(dadj);
    }
    // alias[adj] = k;
//    while(!fruits[adj].empty()) {
//      fruits[k].push(fruits[adj].front());
//      fruits[adj].pop();
//    }

    simplify(k);
  } else {
    for(int adj : children[k]) {
      simplify(adj);
    }
  }
}

void drop(int k) {
  // if(terminated[k]) return;
//  cerr << k << " not terminated " << endl;
  // terminated[k] = fruits[k].empty();

  bool isActive = false;

  int nextF = 0;
  for(int adj : children[k]) {
//    if(terminated[adj]) continue;
//    terminated[k] = false;

    if(!fruits[adj].empty()) {
      isActive = true;
      nextF += fruits[adj].front();
//      cerr << fruits[adj].front() << " dropped from " << adj << " to " << k << endl;
      fruits[adj].pop();
      drop(adj);
    }
  }
  if(isActive) {
//    cerr << k << " filled with " << (nextF % 2) << endl;
    fruits[k].push(nextF % 2);
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n - 1; i++) {
    int parent; scanf("%d", &parent);
    children[--parent].push_back(i + 1);
  }

  for(int i = 0; i < n; i++)
    alias[i] = i;
  simplify(0);
  //  cerr << "simplified" << endl;

  for(int i = 0; i < n; i++)
    fruits[alias[i]].push(1);

  int fruitsCollected = 0;
  while(!fruits[0].empty()) {
//    cerr << "---" << endl;
    fruitsCollected += fruits[0].front();
//    cerr << fruits[0].front() << " collected" << endl;
    fruits[0].pop();
    drop(0);
  }
  printf("%d\n", fruitsCollected);
  return 0;
}
