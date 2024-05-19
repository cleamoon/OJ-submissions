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

ULL pow2 (ULL in, ULL ans=1) {
  if (in == 0) 
    return ans;
  else
    return pow2(in-1, ans*2);
}

int main(void) {
  vector <bool> bl;
  ULL in; 
  cin >> in; 
  while(1) {
    if(in<2) {
      bl.push_back(in);
      break;
    }
    else {
      bl.push_back(in%2);
      in /= 2;
    }
  }
  ULL l = bl.size(), sum=0;
  for(ULL i=0; i<l; i++) {
    if(bl[i]) {
      sum += pow2(l-i-1);
    }
  }
  cout << sum << "\n";
  return 0;
}
