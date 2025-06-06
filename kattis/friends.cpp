#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ULL unsigned 
#define BIG (1000000007)
using namespace std;

ULL n, m, sum=0, tmp;
vector < ULL > ln;
vector < ULL > xors;
map <ULL, ULL> xorsmap;
map <ULL, ULL>::iterator kt;
map <ULL, ULL>::reverse_iterator rt;
vector < ULL >::iterator it, jt;

int main(void) {
  cin >> n >> m;
  for(ULL i=0; i<n; i++) {
    cin >> tmp;
    ln.push_back(tmp);
  }
  for(it = ln.begin(); it != ln.end(); it++) {
    for(jt = it + 1; jt != ln.end(); jt++) {
      tmp = (*it) ^ (*jt);
      kt = xorsmap.find(tmp);
      if (kt == xorsmap.end()) {
	xorsmap.insert( pair <ULL, ULL> (tmp, 1) );
      }
      else {
	kt->second++;
      }
    }
  }
  for(ULL i=0; i<m;) {
    rt = xorsmap.rbegin();
    for (ULL j=0; j<i; j++) 
      rt++;
    ULL upper = (rt->second);
    for(ULL j=0; j<upper; j++) {
      sum += (rt->first);
      sum %= BIG;
    }
    //    sum += (rt->first) * (rt->second);
    //    sum %= BIG;
    //    i += rt->second;
    i += upper;
  }
    
      /*      xors.push_back(tmp);
    }
  }
  sort(xors.begin(), xors.end());
  for(ULL i=0; i<m; i++) {
    sum += *(xors.end()-1-i);
    sum %= BIG;
    }*/
      
  cout << sum << endl;
  return 0;
}
