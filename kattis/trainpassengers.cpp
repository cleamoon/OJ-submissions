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
//using namespace std;

typedef long long ULL;

int main(void) {
  ULL c, n, a, b, d, curr=0;
  bool ok=true;
  cin >> c >> n;
  for(ULL i=0; i<n; i++) {
    cin >> a >> b >> d;
    curr -= a;
    if(curr < 0) {
      ok = false;
      break;
    }
    curr += b;
    if(curr >c) {
      ok = false;
      break;
    }
    if((d != 0) && (curr < c)) {
      ok = false;
      break;
    }
  }
  if(curr != 0) {
    ok = false;
  }
  if(ok) {
    cout << "possible\n";
  }
  else {
    cout << "impossible\n";
  }
  return 0;
}
