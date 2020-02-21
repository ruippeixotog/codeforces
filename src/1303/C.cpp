#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; getline(cin, s);

    set<int> adjs[26];
    for(int i = 1; i < s.length(); i++) {
      adjs[s[i - 1] - 'a'].insert(s[i] - 'a');
      adjs[s[i] - 'a'].insert(s[i - 1] - 'a');
    }

    string keyboard;
    bool valid = true; int start = -1;
    for(int i = 0; i < 26; i++) {
      switch(adjs[i].size()) {
        case 0: keyboard.push_back('a' + i); break;
        case 1: start = i; break;
        case 2: break;
        default: valid = false;
      }
    }

    if(s.size() == 1) {
      printf("YES\n");
      printf("%s\n", keyboard.c_str());
    } else if(valid && start != -1) {
      printf("YES\n");
      keyboard.push_back('a' + start);
      while(!adjs[start].empty()) {
        int next = *adjs[start].begin();
        adjs[next].erase(start);
        keyboard.push_back('a' + next);
        start = next;
      }
      printf("%s\n", keyboard.c_str());
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
