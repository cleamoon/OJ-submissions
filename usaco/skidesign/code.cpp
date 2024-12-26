/*
ID: cleamoo1
TASK: skidesign
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ofstream fout("skidesign.out");
  ifstream fin("skidesign.in");
  int len;
  fin >> len;

  vector<int> heights;

  for (int i = 0; i < len; i++) {
    int height;
    fin >> height;
    heights.push_back(height);
  }

  sort(heights.begin(), heights.end());

  int ans = 0;

  auto begin = heights.begin();
  auto end = heights.end() - 1;

  while (begin != end) {
    int diff = *end - *begin;
    if (diff <= 17) {
      end--;
    } else {
        }
  }

  return 0;
}