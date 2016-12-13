#include <cstdio>
#include <vector>

#define MAXN 100

using namespace std;

int crush[MAXN];

bool visited[MAXN];
vector<int> cycles;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int n; scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &crush[i]);

  bool fail = false;
  for(int i = 0; i < n; i++) {
    if(visited[i]) continue;

    int curr = i, len = 0;
    while(!visited[curr]) {
      visited[curr] = true;
      curr = crush[curr] - 1;
      len++;
    }
    if(curr == i) cycles.push_back(len % 2 ? len : len / 2);
    else { fail = true; break; }
  }

  int res = -1;
  if(!fail) {
    res = 1;
    for(int len: cycles) res = lcm(res, len);
  }

  printf("%d\n", res);
  return 0;
}
