#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define ULL unsigned long long
using namespace std;

ULL test_case, place, key, alpha, tmp;

vector <ULL> freq;

bool comp(ULL a, ULL b) { return a<b; }

int main(void) {
  cin >> test_case;
  for(ULL t=0; t<test_case; t++) {
    ULL result = 0;
    cin >> place >> key >> alpha;
    for(ULL i=0; i<alpha; i++) {
      cin >> tmp;
      freq.push_back(tmp);
    }
    sort(freq.begin(), freq.end(), comp);
    for(ULL vikt=1;; vikt ++) {
      for(ULL j=0; j<key; j++) {
	if(!freq.empty()) {
	  result += freq.back()*vikt;
	  //	  cout << result << endl;
	  freq.pop_back();
	}
	else {
	  break;
	}
      }
      if(freq.empty()) {
	break;
      }
    }
    cout << "Case #" << t+1 << ": " << result << endl;
  }
  return 0;
}
