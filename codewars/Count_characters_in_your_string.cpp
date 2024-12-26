#include <map>
#include <string>

std::map<char, unsigned> count(const std::string& string) {
  std::map<char, unsigned> res = {};
  for(auto i = 0; i < string.length(); i++) {
    auto it = res.find(string[i]);
    if (it == res.end()) {
      res.insert(std::pair<char, unsigned>(string[i], 1));
    } else {
      it->second ++;
    }
  }
  return res;
}
