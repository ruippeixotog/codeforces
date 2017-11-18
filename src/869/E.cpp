#include <cstdio>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

// ----

template<class Node, class Op> struct SegTree {
  int size;
  vector<Node> tree;

  SegTree(int n) {
    size = n;
    tree.resize(4 * n + 1);
  }

  inline int left(int node) { return 2 * node; }
  inline int right(int node) { return 2 * node + 1; }

  ll query(int node, int st, int end, int i, int c) {
    if (st == i && end == i) return tree[node].idFor(c);

    ll childId = i <= (st + end) / 2 ?
                 query(left(node), st, (st + end) / 2, i, c) :
                 query(right(node), (st + end) / 2 + 1, end, i, c);

    return childId != -1 ? childId : tree[node].idFor(c);
  }

  void update(int node, int st, int end, int i, int j, Op op) {
    if (j < st || i > end) return;
    if (st >= i && end <= j) { op.apply(tree[node], st, end); return; }

    if(i <= (st + end) / 2) update(left(node), st, (st + end) / 2, i, j, op);
    if(j > (st + end) / 2) update(right(node), (st + end) / 2 + 1, end, i, j, op);
  }

  ll query(int i, int c) { return query(1, 0, size - 1, i, c); }
  void update(int i, int j, Op op) { return update(1, 0, size - 1, i, j, op); }
};

struct Border {
  int c1, c2; ll id;
  Border(int _r1, int _c1, int _c2):
    c1(_c1), c2(_c2), id(_r1 + 10000 * _c1 + 100000000L * (_c2 - _c1)) {}
};

struct Node {
  vector<Border> borders;

  ll idFor(int c) {
    ll best = -1, dim = INF;
    for(auto b : borders) {
      if(b.c1 <= c && c <= b.c2 && b.c2 - b.c1 < dim) {
        best = b.id;
        dim = b.c2 - b.c1;
      }
    }
    return best;
  }
};

struct Op {
  bool ins; Border b;
  Op(bool _ins, Border _b): ins(_ins), b(_b) {}

  void apply(Node& node, int st, int end) {
    if(ins) {
      node.borders.push_back(b);
    } else {
      for(auto it = node.borders.begin(); it != node.borders.end(); it++) {
        if(it->id == b.id) { node.borders.erase(it); break; }
      }
    }
  }
};

// ----

int main() {
  int n, m, q; scanf("%d %d %d\n", &n, &m, &q);
  SegTree<Node, Op> tree(n);

  while(q--) {
    int op, ra, ca, rb, cb; scanf("%d %d %d %d %d\n", &op, &ra, &ca, &rb, &cb);
    ra--; ca--; rb--; cb--;

    if(op == 3) {
      ll id1 = tree.query(ra, ca);
      ll id2 = tree.query(rb, cb);
      printf("%s\n", id1 == id2 ? "Yes" : "No");
      continue;
    }

    int r1 = min(ra, rb), r2 = max(ra, rb), c1 = min(ca, cb), c2 = max(ca, cb);
    tree.update(r1, r2, Op(op == 1, Border(r1, c1, c2)));
  }
  return 0;
}
