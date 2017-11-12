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

int n; string strs[MAXN];
int letters[26];

bool tryJoin(int i, int j, char ch) {
  if(strs[i].find(strs[j]) != -1) return true;
  else if(strs[j].find(strs[i]) != -1) { strs[i] = strs[j]; return true; }
  else {
    int ijOverlap = -1;
    for(int si = 0; si < strs[i].size(); si++) {
      if(ijOverlap == -1) { if(strs[i][si] == strs[j][0]) ijOverlap = si; }
      else if(strs[i][si] != strs[j][si - ijOverlap]) { ijOverlap = -1; break; }
    }
    int jiOverlap = -1;
    for(int sj = 0; sj < strs[j].size(); sj++) {
      if(jiOverlap == -1) { if(strs[j][sj] == strs[i][0]) jiOverlap = sj; }
      else if(strs[j][sj] != strs[i][sj - jiOverlap]) { jiOverlap = -1; break; }
    }
    if((ijOverlap > 0) == (jiOverlap > 0)) return false;
    if(ijOverlap > 0) strs[i] += strs[j].substr(strs[i].size() - ijOverlap);
    if(jiOverlap > 0) strs[i] = strs[j] + strs[i].substr(strs[j].size() - jiOverlap);
  }
  return true;
}

bool build2(int i, string& lettersToCheck, int j0) {
//  cerr << "build " << i << "," << lettersToCheck << "," << j0 << endl;

  for(int j = j0; j < lettersToCheck.size(); j++) {
    int letterOwner = letters[lettersToCheck[j] - 'a'];
    if(letterOwner == -1) {
      letters[lettersToCheck[j] - 'a'] = i;
    } else {
      if(letterOwner == i) {
        if(count(strs[i].begin(), strs[i].end(), lettersToCheck[j]) > 1) {
          return false;
        }
      } else {
//        cerr << "join " << strs[letterOwner] << " with " << strs[i] << endl;

        if(tryJoin(letterOwner, i, lettersToCheck[j])) {
//          cerr << "joined as " << strs[letterOwner] << endl;

          for(int k = 0; k < strs[i].size(); k++) {
            bool found = false;
            for(int k2 = j + 1; k2 < lettersToCheck.size(); k2++) {
              if(strs[i][k] == lettersToCheck[k2]) {
                found = true;
                break;
              }
            }
            if(!found) letters[strs[i][k] - 'a'] = letterOwner;
          }
          if(!build2(letterOwner, lettersToCheck, j + 1)) {
            return false;
          }
          strs[i] = "";
          break;
        } else {
//          cerr << "couldn't join" << endl;
          return false;
        }
      }
    }
  }
  return true;
}

string build() {
  memset(letters, -1, sizeof(letters));
  for(int i = 0; i < n; i++) {
    if(!build2(i, strs[i], 0)) return "NO";
//    for(int j = 0; j < strs[i].size(); j++) {
//      int letterOwner = letters[strs[i][j] - 'a'];
//      if(letterOwner == -1) {
//        letters[strs[i][j] - 'a'] = i;
//      } else {
//        if(letterOwner != i && tryJoin(letterOwner, i)) {
////          cerr << "joined as " << strs[letterOwner] << endl;
//
//          for(int k = 0; k <= j; k++) {
//            letters[strs[i][k] - 'a'] = letterOwner;
//          }
//          for(int k = j + 1; k < strs[i].size(); k++) {
//            if(letters[strs[letterOwner][k] - 'a'] != -1) return "NO";
//            letters[strs[letterOwner][k] - 'a'] = letterOwner;
//          }
//
////          for(int k = 0; k < strs[letterOwner].size(); k++) {
////            letters[strs[letterOwner][k] - 'a'] = -1;
////          }
////          for(int k = 0; k < strs[letterOwner].size(); k++) {
////            if(letters[strs[letterOwner][k] - 'a'] != -1) return "NO";
////            letters[strs[letterOwner][k] - 'a'] = letterOwner;
////          }
//          strs[i] = "";
//          break;
//        } else {
////          cerr << "couldn't join" << endl;
//          return "NO";
//        }
//      }
//    }
  }
  sort(strs, strs + n);
  string res;
  for(int i = 0; i < n; i++) {
    res += strs[i];
  }
  return res;
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    cin >> strs[i];

  printf("%s\n", build().c_str());
  return 0;
}
