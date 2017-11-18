#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

char str[MAXN + 1];

template<class Node> struct SegTree {
  int size;
  vector<Node> tree;

  SegTree(int n) {
    size = n;
    tree.resize(4 * n + 1);
  }

  SegTree(int n, char* arr): SegTree(n) {
    build(arr);
  }

  inline int left(int node) { return 2 * node; }
  inline int right(int node) { return 2 * node + 1; }

  void build(char* arr, int node, int st, int end) {
    if (st == end) { tree[node] = Node(st, arr[st]); return; }

    build(arr, left(node), st, (st + end) / 2);
    build(arr, right(node), (st + end) / 2 + 1, end);
    tree[node] = tree[left(node)].join(tree[right(node)]);
  }

  Node query(int node, int st, int end, int i, int j) {
    if (j < st || i > end) return Node();
    if (st >= i && end <= j) return tree[node];

    Node p1 = query(left(node), st, (st + end) / 2, i, j);
    Node p2 = query(right(node), (st + end) / 2 + 1, end, i, j);
    return p1.join(p2);
  }

  void build(char* arr) { build(arr, 1, 0, size - 1); }
  Node query(int i, int j) { return query(1, 0, size - 1, i, j); }
};

struct Node {
  int prefix[5][5];

  Node() {
    memset(prefix, 0x3f, sizeof(prefix));
    for(int i = 0; i < 5; i++)
      prefix[i][i] = 0;
  }

  Node(int idx, char ch): Node() {
    if(ch == '2') { prefix[0][0] = 1; prefix[0][1] = 0; }
    else if(ch == '0') { prefix[1][1] = 1; prefix[1][2] = 0; }
    else if(ch == '1') { prefix[2][2] = 1; prefix[2][3] = 0; }
    else if(ch == '7') { prefix[3][3] = 1; prefix[3][4] = 0; }
    else if(ch == '6') { prefix[3][3] = 1; prefix[4][4] = 1; }
  }

  Node join(Node& o) {
    Node n;
    memset(n.prefix, 0x3f, sizeof(n.prefix));

    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
          n.prefix[i][k] = min(
            n.prefix[i][k],
            prefix[i][j] + o.prefix[j][k]);
        }
      }
    }
    return n;
  }
};

int main() {
  int n, q; scanf("%d %d\n", &n, &q);
  scanf("%s\n", str);

  SegTree<Node> tree(n, str);
  while(q--) {
    int a, b; scanf("%d %d\n", &a, &b);
    Node res = tree.query(a - 1, b - 1);
    printf("%d\n", res.prefix[0][4] != INF ? res.prefix[0][4] : -1);
  }
  return 0;
}
