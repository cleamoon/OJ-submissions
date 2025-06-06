#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;

int main(void) {
  LL t; cin >> t;
  for(LL i=0; i<t; i++) {
    LL n; cin >> n;
    set <string> num;
    for(LL j=0; j<n; j++) {
      string tmp; cin >> tmp;
      num.insert(tmp);
    }
    bool issame = false;
    for(set <string>::iterator it=num.begin(); it!=num.end(); it++) {
      LL l=it->length();
      for(LL j=1; j<l; j++) {
	if(num.find(it->substr(0, l-j))!=num.end()) {
	//  cout << it->substr(0, l-j) << endl; 
	  issame = true;
	  goto done;
	}
      }
    }
done:
    if(issame) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
