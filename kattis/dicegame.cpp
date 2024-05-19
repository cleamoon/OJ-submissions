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

typedef unsigned ULL;

int main(void) {
  ULL a1, a2, a3, a4, b1, b2, b3, b4;
  cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4;
  ULL a = a1+a2+a3+a4, b = b1+b2+b3+b4;
  if(a<b) 
    cout << "Emma\n";
  else if(a==b) 
    cout << "Tie\n";
  else
    cout << "Gunnar\n";
  return 0;
}
