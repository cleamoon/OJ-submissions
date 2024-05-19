/*
ID: cleamoo1
TASK: combo
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int n, a, b, c, x, y, z;

bool near(int x, int y) {
  if (abs(x - y) <= 2) {
    return true;
  } else if (abs(x - y) >= n - 2) {
    return true;
  }
  return false;
}

int main() {
  ofstream fout("combo.out");
  ifstream fin("combo.in");
  fin >> n;
  fin >> a >> b >> c;
  fin >> x >> y >> z;

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if ((near(i, a) && near(j, b) && near(k, c)) ||
            (near(i, x) && near(j, y) && near(k, z))) {
          ans += 1;
        }
      }
    }
  }

  fout << ans << endl;
  return 0;
}