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

struct node {
  ULL data;
  struct node* left;
  struct node* right;
};

ULL h;

string path;

struct node* root = NULL;

int main(void) {
  cin >> h;
  h++;
  ULL lim=1;
  for(ULL i=0; i<h; i++) {
    lim *= 2;
  }
  lim --;
//  cout << lim << endl;
  if(cin >> path) {
    ULL tmp = 1;
    for(ULL i=0; i<path.size(); i++) {
      if(path[i] == 'L') {
	tmp *= 2;
      }
      else {
	tmp *= 2;
	tmp ++;
      }
    }
    cout << lim-tmp+1 << endl;
  }
  else {
    cout << lim << endl;
  }
  return 0;
}
