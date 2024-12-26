#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct LC {
  int x;
  int y;
};

inline int abs(int a, int b) {
  if (a>= b)
    return a-b;
  else
    return b-a;
}

inline int dist (LC a, LC b) {
  return abs(a.x-b.x) + abs(a.y-b.y);
}

int number;
vector <LC> plist;
queue <int> q;
vector <bool> checked;

inline bool bfs () {
  while(1) {
    if (q.empty()) {
      return false;
    }
    else {
      LC here = plist[q.front()];
      checked[q.front()] = true;      
      //      cout << here.x << " " << here.y << " " << q.size() << endl;
      for(int i=1; i<number; i++) {
	if ((!checked[i])&&(dist(here, plist[i])<=1000)) {
	  //	  cout << i << endl;
	  if (i==number-1) {
	    return true;
	  }
	  else {
	    q.push(i);
	  }
	}
	/*	else {
	  checked [i] = true;
	  }*/
      }
      q.pop();
    }
  }
}
	
int main(void) {
  int test_case;
  cin >> test_case;
  for (int t=0; t<test_case; t++) {
    // INITIAL
    cin >> number;
    number += 2;
    while(1) {
      if (!q.empty()) {
	q.pop();
      }
      else {
	break;
      }
    }
    while(1) {
      if (!plist.empty()) {
	plist.pop_back();
      }
      else {
	break;
      }
    }
    while(1) {
      if (!checked.empty()) {
	checked.pop_back();
      }
      else {
	break;
      }
    }
    //    plist = new LC [number];
    //    checked = new bool [number];
    //    memset (checked, false, number);
    for (int i=0; i<number; i++) {
      checked.push_back(false);
    }
    for(int i=0; i<number; i++) {
      LC tmp;
      cin >> tmp.x >> tmp.y;
      plist.push_back(tmp);
    }
    // BFS
    q.push(0);
    //    checked[0] = true;
    if(bfs()) {
      cout << "happy" << endl;
    }
    else {
      cout << "sad" << endl;
    }
  }
  return 0;
}
