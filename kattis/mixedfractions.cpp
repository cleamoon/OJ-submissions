#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long ULL;

int main(void) {
  ULL x, y;
  while(cin >> x >> y) {
    if ( x == 0 && y == 0) 
      break;
    else
      cout << x/y << " " << x%y << " / " << y << "\n";
  }
  return 0;
}
