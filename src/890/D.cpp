#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>

#define MAXN 100000

using namespace std;

int n; string strs[MAXN];
int letters[26];

bool validate(string& str) {
  if(str.size() > 26) return false;
  bool found[26];
  memset(found, false, sizeof(found));

  for(char ch : str) {
    if(found[ch - 'a']) return false;
    found[ch - 'a'] = true;
  }
  return true;
}

string appendJoin(string& str1, string& str2) {
  int overlap = str1.find(str2[0]);
  if(overlap == -1) return "";

  for(int i = overlap + 1; i < str1.size() && i - overlap < str2.size(); i++) {
    if(str1[i] != str2[i - overlap]) return "";
  }
  return str1 + str2.substr(str1.size() - overlap);
}

bool tryJoin(string& str1, string& str2) {
  if(str1.find(str2) != -1) return true;
  else if(str2.find(str1) != -1) { str1 = str2; return true; }
  else {
    string joined = appendJoin(str1, str2);
    if(joined.empty()) joined = appendJoin(str2, str1);
    if(joined.empty()) return false;
    str1 = joined;
  }
  return true;
}

string build() {
  memset(letters, -1, sizeof(letters));
  for(int i = 0; i < n; i++) {
    if(!validate(strs[i])) return "NO";

    set<int> toJoin;
    for(int j = 0; j < strs[i].size(); j++) {
      if(letters[strs[i][j] - 'a'] == -1) letters[strs[i][j] - 'a'] = i;
      else toJoin.insert(letters[strs[i][j] - 'a']);
    }

    for(int j : toJoin) {
      if(!tryJoin(strs[i], strs[j])) return "NO";
      for(int k = 0; k < 26; k++) {
        if(letters[k] == j) letters[k] = i;
      }
      strs[j] = "";
    }
    if(!validate(strs[i])) return "NO";
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
