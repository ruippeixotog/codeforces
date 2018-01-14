#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string a, b;
int hist[10]; string res;

bool go(int bi, bool buildMax) {
  if(bi == a.size()) return true;

  int digit = b[bi] - '0';
  int high = buildMax ? 9 : digit;

  for(int d = high; d >= 0; d--) {
    if(!hist[d]) continue;
    res.push_back((char) ('0' + d));
    hist[d]--;
    if(go(bi + 1, buildMax || d < digit)) return true;
    hist[d]++;
    res.pop_back();
  }
  return false;
}

int main() {
  cin >> a >> b;
  for(char ch : a)
    hist[ch - '0']++;

  go(0, b.size() > a.size());
  printf("%s\n", res.c_str());
  return 0;
}
