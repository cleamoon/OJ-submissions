#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  std::vector<int> res;
  for (auto i = 0; i < input.size(); i++) {
    if (input[i] != 0) {
      res.push_back(input[i]);
    }
  }
  for (auto i = res.size(); i < input.size(); i++) {
    res.push_back(0);
  }
  return res;
}