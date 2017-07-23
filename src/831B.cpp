#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string first, second, input;
  getline(cin, first); getline(cin, second); getline(cin, input);

  string output;
  for(char ch : input) {
    char newCh =
      ch >= 'a' && ch <= 'z' ? second[first.find(ch)] :
      ch >= 'A' && ch <= 'Z' ? toupper(second[first.find(tolower(ch))]) :
      ch;

    output.push_back(newCh);
  }
  cout << output << endl;
  return 0;
}
