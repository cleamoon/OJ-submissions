#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int lim = 32001;
  int squ = (int)(sqrt(lim)+1);
  vector<bool> prime(lim, true);
  //prime[2] = false;
  //cout << squ << endl;
  for(int i=3; i<squ; i += 2) {
    if (prime[i]) {
      for(int j=i*i; j<=lim; j+=i) {
	//	if (i == 5)
	//	cout << j << endl;
	prime[j] = false;
      }
    }
  }
  for(int i=3; i<lim; i += 2) {
    //    if(prime[i]) cout << i << endl;
  }
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int in;
    cin >> in;
    if (in == 4) {
      cout << "4 has 1 representation(s)" << endl << "2+2" << endl << endl;
      continue;
    }
    vector <pair<int, int> > p;
    for(int j=3; j*2<=in; j += 2) {
      if(prime[j] && prime[in-j]) {
	p.push_back(make_pair(j, in-j));
      }
    }
    cout << in << " has " << p.size() << " representation(s)" << endl;
    for(int j=0; j<p.size(); j++) {
      cout << p[j].first << '+' << p[j].second << endl;
    }
    cout << endl;
  }
}
