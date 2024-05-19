#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(void) {
  int n;
  unordered_map<string, int> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    auto it = s.find(str);
    if (it == s.end()) {
      cout << "OK\n";
      s.insert(make_pair(str, 0));
      continue;
    }
    it->second ++;
    cout << str << it->second << '\n';
  }
  return 0;
}
