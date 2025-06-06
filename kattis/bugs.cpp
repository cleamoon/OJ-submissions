#include <iostream>
#include <string>
#include <cstdio>
#define ULL unsigned long long
using namespace std;

ULL amount;
string bug, tmp;

inline string remove(string orig) {
  size_t s=bug.size();
  string out=orig;
  string::iterator tmp;
  size_t found;
  size_t pos=0;
  while(1) {
    found = out.find(bug, pos);
    if(found != string::npos) {
      tmp = out.begin()+found;
      out.erase(tmp, tmp+s);
      pos = found;
    }
    else {
      if(pos==0) {
	break;
      }
      else {
	pos = 0;
	continue;
      }
    }
  }
  return out;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> amount >> bug) {
    //    cout << amount << "  " << bug << endl;
    getline(cin, tmp);
    for(ULL i=0; i<amount; i++) {
      string input;
      getline(cin, input);
      //      cout << input << endl;
      if(input.size()>=bug.size()) {
	printf("%s\n", remove(input).c_str());
      }
      else {
	printf("%s\n", input.c_str());
      }
    }
  }
  return 0;
}
