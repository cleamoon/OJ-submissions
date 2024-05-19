#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
//#define DEBUG
using namespace std;

vector < int > kassor;
queue < int > wait;
int l_queue, n_kassor;

void init () {
  cin >> l_queue >> n_kassor;
  if (l_queue<n_kassor) {
    cout << "0" << endl;
    exit(0);
  }
  for(int i=0; i<l_queue; i++) {
    int tmp;
    cin >> tmp;
    wait.push(tmp);
  }
  for(int i=0; i<n_kassor; i++) {
    kassor.push_back(wait.front());
    wait.pop();
  }
}

int min(vector < int > v) {
  int m = 99999;
  for(vector < int >::iterator it=v.begin(); it != v.end(); it++) {
    if (*it < m)
      m = *it;
  }
  return m;
}

int main (void) {
  init();
#ifdef DEBUG
  for(vector < int >::iterator it=kassor.begin(); it != kassor.end();
      it ++)
    cout << *it << endl;
#endif
  for(int i=1; ; i++) {
    // if(wait.empty()) {
    //   cout << i << endl;
    //   return 0;
    // }
    //    else {
#ifdef DEBUG
      cout << "HERE" << endl;
#endif
      for(vector < int >::iterator it = kassor.begin();
	  it != kassor.end(); ++it ) {
	(*it) --;
#ifdef DEBUG
	cout << "*it=" << *it << endl <<
	  "diff=" << it - kassor.begin() << endl << endl;
#endif
      }
      for(vector < int >::iterator it = kassor.begin();
	  it != kassor.end(); it++) {
	if(*it == 0) {
	  if (wait.empty()) {
	    cout << i << endl;
	    return 0;
	  }
	  else {
	    kassor.erase(it);
	    kassor.insert(it, wait.front());
	    wait.pop();
	  }
	}
      }
#ifdef DEBUG
      cout << "COME HERE" << endl;
#endif
      // for(vector < int >::iterator it = kassor.begin();
      // 	  it != kassor.end(); it++) {
      // 	if (*it == 0) {
      // 	  kassor.erase(it);
      // 	  it--;
      // 	  if (kassor.empty()) {
      // 	    break;
      // 	  }
      // 	}
      // }
      // for(int j=0; j<n_kassor-(int)kassor.size(); j++) {
      // 	if(wait.empty()) {
      // 	  cout << (i+min(kassor)) << endl;
      // 	  return 0;
      // 	}
      // 	kassor.push_back(wait.front());
      // 	wait.pop();
      // }
#ifdef DEBUG
      for(vector < int >::iterator it=kassor.begin();
	  it != kassor.end(); it++) {
	cout << *it << " ";
      }
      cout << endl;
#endif
    }
  }
//}
