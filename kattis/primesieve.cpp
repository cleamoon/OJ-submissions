#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

int main(void) {
  ULL n, p, tmp, ansn=0;
  cin >> n >> p;
  //cout << n << p << endl;
  ULL lim = 1e8 + 1, halvlim = 1e4 + 1;
  vector <bool> list (lim, true);
  /*
  for(ULL i=0; i<lim; i++) {
  	list.push_back(true);
  }
  */
  /*
  ULL *ans;
  ans = (ULL *) malloc (lim * sizeof(ULL));
  memset (ans, 0, lim);
  */
  list[0] = false;
  list[1] = false;
  //list[2] = true;
  /*ans[0] = 0;
  ans[1] = 0;
  ans[2] = 1;*/
  ULL curr = 0;
  for(ULL i=2; i<halvlim; i++) {
  	//cout << "yeeeeeeeeees\n";
    //ans[i] = curr;
    if(list[i]) {
      curr += 1;
      //ans[i] += 1;
      //list[i] = false;
      tmp = i*i;
      while(1) {
        //tmp = i*j;
        if(tmp > lim) break;
        list[tmp] = false;
        tmp += i;
      }
    }
/*    if(i == n) {
      ansn = curr;
    }*/
  }
  for(ULL i=2; i<=n; i++) {
  	if(list[i]) ansn++;
  }
  cout << ansn << "\n";
  for(ULL i=0; i<p; i++) {
    cin >> tmp;
    if(list[tmp])
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
/*
  cout << "vector <ULL> p = {";
  for(ULL i=0; i<lim; i++) {
  	if(list[i]) cout << i << ",";
  }
  cout << "\b};";
  return 0;
  */
}

/*
int main(void) {

}
*/