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

ULL calc(ULL in, ULL ans=0) {
  if (in < 10) 
    return ans+in;
  else
    return calc(in/10, ans+in%10);
}

int main(void) {
  ULL in;
  while( cin >> in) {
    if (in == 0) break;
    for(ULL ans=11;; ans++) {
      if(calc(in) == calc(in*ans)) {
	cout << ans << "\n";
	break;
      }
    }
  }
  return 0;
}
