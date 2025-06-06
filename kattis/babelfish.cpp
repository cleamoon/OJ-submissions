#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
  map <string, string> m;
  string line, key, value;
  while(1) {
    getline(cin, line);
    //cout << line << endl;
    if(line=="") {
      while(1) {
	if(cin >> key) {
	  map <string, string>::iterator it=m.find(key);
	  if(it!=m.end())
	    cout << it->second << endl;
	  else
	    cout << "eh" << endl;
	}
	else {
	  return 0;
	}
      }
    }
    stringstream ss(line);
    ss >> value >> key;
    m.insert(make_pair(key, value));
  }
}
