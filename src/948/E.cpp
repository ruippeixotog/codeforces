#include <algorithm>
#include <iostream>
#include <string>

#define MAXS 100000

using namespace std;

int sBcCount[MAXS + 1], tBcCount[MAXS + 1];
int sATail[MAXS + 1], tATail[MAXS + 1];

void preprocess(string& str, int* bcCount, int* aTail) {
  bcCount[0] = aTail[0] = 0;
  for(int i = 0; i < str.length(); i++) {
    bcCount[i + 1] = bcCount[i] + (str[i] != 'A');
    aTail[i + 1] = str[i] == 'A' ? aTail[i] + 1 : 0;
  }
}

int getBcCount(int* bcCount, int from, int to) {
  return bcCount[to] - bcCount[from - 1];
}

int getATail(int* aTail, int from, int to) {
  return min(aTail[to], to - from + 1);
}

int main() {
  string s, t; cin >> s >> t;
  preprocess(s, sBcCount, sATail);
  preprocess(t, tBcCount, tATail);

  int q; scanf("%d\n", &q);
  for(int i = 0; i < q; i++) {
    int ai, bi, ci, di; cin >> ai >> bi >> ci >> di;

    int sbc = getBcCount(sBcCount, ai, bi),
      tbc = getBcCount(tBcCount, ci, di),
      sat = getATail(sATail, ai, bi),
      tat = getATail(tATail, ci, di);

    if(sbc > tbc) {
      cout << 0;
    } else if(sbc == tbc) {
      cout << (sat >= tat && (sat - tat) % 3 == 0);
    } else if(sbc == 0) {
      cout << (tbc % 2 == 0 && sat > tat);
    } else {
      cout << ((tbc - sbc) % 2 == 0 && sat >= tat);
    }
  }
  cout << endl;
  return 0;
}
