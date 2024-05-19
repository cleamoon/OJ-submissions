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
//#include <list>
#include <map>
#include <set>
using namespace std;

#define MAX 50001
#define LIM 10001

typedef unsigned ULL;

/*vector <ULL> list;

ULL calc(ULL in) {
  if (list[in] != 0) 
    return list[in];
  else {
    if (in%2 == 0) {
      ULL tmp = calc (in/2) + 1;
      list[in] = tmp;
      return tmp;
    }
    else {
      ULL tmp = calc(in*3+1) + 1;
      list[in] = tmp;
      return tmp;
    }
  }
}

int main(void) {
  list.push_back(0);
  for(ULL i=1; i<MAX; i++) {
    list.push_back(0);
  }
  list[1] = 1;
//  cout << "afasfs" << endl;
  ULL x, y;
  cin >> x >> y;
  for(ULL i=x; i<=y; i++) {
    scanf("%u\n", (unsigned)calc(i) );
  }
  return 0;
}*/

ULL calc(ULL in, ULL ans=0) {
  if(in==1) 
    return ans;
  else 
    if(in%2 == 0) 
      return calc(in/2, ans+1);
    else
      return calc(in*3+1, ans+1);
}

int main(void) {
  ULL x, y;
  cin >> x >> y;
  for(ULL i=x; i<=y; i++) {
    cout << calc(i) << endl;
  }
  return 0;
}
