#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>

#define MAXM 100

using namespace std;

int m;
set<string> usernames;

string msgs[MAXM];
set<string> restrictions[MAXM];
bool expanded[MAXM];

bool expand(int i) {
  if(!expanded[i] && restrictions[i].size() == 1) {
    expanded[i] = true;

    string user = *restrictions[i].begin();
    if(i > 0) {
      restrictions[i - 1].erase(user);
      if(!expand(i - 1)) return false;
    }
    if(i < m - 1) {
      restrictions[i + 1].erase(user);
      if(!expand(i + 1)) return false;
    }
  }
  return !restrictions[i].empty();
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);

    usernames.clear();
    for(int i = 0; i < n; i++) {
      string user; cin >> user;
      usernames.insert(user);
    }

    scanf("%d\n", &m);
    for(int i = 0; i < m; i++) {
      getline(cin, msgs[i]);

      int sep = msgs[i].find(':');
      string user = msgs[i].substr(0, sep);
      msgs[i] = msgs[i].substr(sep + 1);

      if(user != "?") {
        restrictions[i] = { user };
      }
      else {
        restrictions[i] = usernames;
        for(int prevIdx = -1; prevIdx < (int) msgs[i].size(); ) {
          int idx = msgs[i].find_first_of(".,!? ", ++prevIdx);
          if(idx == -1) idx = msgs[i].size();

          if(idx != prevIdx) {
            string word = msgs[i].substr(prevIdx, idx - prevIdx);
            if(usernames.count(word)) restrictions[i].erase(word);
          }
          prevIdx = idx;
        }
      }
    }

    memset(expanded, false, sizeof(expanded));
    bool impossible = false;
    for(int i = 0; i < m; i++) {
      if(!expand(i)) { impossible = true; break; }
    }

    if(impossible) printf("Impossible\n");
    else {
      for(int i = 0; i < m; i++) {
        string user = *restrictions[i].begin();
        if(i < m - 1) restrictions[i + 1].erase(user);
        printf("%s:%s\n", user.c_str(), msgs[i].c_str());
      }
    }
  }
  return 0;
}
