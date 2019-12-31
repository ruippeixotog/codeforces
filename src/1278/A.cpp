#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string p, h;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    getline(cin, p);
    getline(cin, h);

    vector<int> histP(26, 0);
    for(char ch : p) {
      histP[ch - 'a']++;
    }

    bool found = false;
    for(int i = 0; i <= (int) h.length() - (int) p.length() && !found; i++) {
      vector<int> histH(26, 0);
      for(int j = i; j < i + (int) p.length(); j++) {
        histH[h[j] - 'a']++;
      }
      found = histP == histH;
    }
    printf("%s\n", found ? "YES" : "NO");
  }
  return 0;
}
