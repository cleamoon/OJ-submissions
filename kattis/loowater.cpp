#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ULL unsigned
#define END "Loowater is doomed!\n"
using namespace std;

ULL head, knight, tmp;
vector <ULL> d, l;

bool comp(ULL a, ULL b) { return a > b; }

void clean () {
  while(1) {
    if(!d.empty())
      d.pop_back();
    else
      break;
  }
  while(1) {
    if(!l.empty())
      l.pop_back();
    else
      break;
  }
}

/*void debug(vector <ULL> a) {
  for(ULL i=0; i<a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
  }*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ULL ok=1;
  while(ok) {
    cin >> head >> knight;
    if ((head==0)&&(knight==0)) {
      return 0;
    }
    if (head>knight) {
      cout << END;
      for(ULL i=0; i<head; i++) {
	cin >> tmp;
      }
      for(ULL i=0; i<knight; i++) {
	cin >> tmp;
      }
      continue;
    }
    ULL res=0;
    bool done = true;
    for(ULL i=0; i<head; i++) {
      cin >> tmp;
      d.push_back(tmp);
    }
    for(ULL i=0; i<knight; i++) {
      cin >> tmp;
      l.push_back(tmp);
    }
    sort(d.begin(), d.end(), comp);
    sort(l.begin(), l.end(), comp);
    if(d[0]>l[0]) {
      cout << END;
      clean();
      continue;
    }
    for(ULL i=0; i<head; i++) {
      done = false;
      //      debug(d);
      //      debug(l);
      for(ULL j=0; j<l.size(); j++) {
	if ((l[j]>=d[i])&&((j==l.size()-1)||(l[j+1]<d[i]))) {
	  res += l[j];
	  //	  cout << l.size() << d.size()<< "afasf" << endl;
	  l.erase(l.begin()+j);
	  done = true;
	  break;
	}
      }
      if(!done)
	break;
    }
    if(done) {
      cout << res << "\n";
    }
    else {
      cout << END;
    }
    clean();
  }
}
