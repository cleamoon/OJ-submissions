#include <bits/stdc++.h>
#define LL int
#define GIVE {cout << "invalid\n"; return 0;}

using namespace std;

int main(void) {
  LL space[8][8];
  char c;
  vector < pair <LL, LL> > q;
  for(LL i=0; i<8; i++) {
    for(LL j=0; j<8; j++) {
      c = getchar();
      if(c=='*') {
	space[i][j] = 1;
	q.push_back(make_pair(i,j));
      }
      else
	space[i][j] = 0;
    }
    getchar();
  }
  /*
  for(LL i=0; i<8; i++) {
    for(LL j=0; j<8; j++) {
      cout << space[i][j];
    }
    cout << endl;
  }
  
  for(auto v : q) {
    cout << v.first << " " << v.second << endl;
  }
  */
  if(q.size() != 8) GIVE;
  for(auto v : q) {
    for(LL i=1; i<8; i++) {
      if((v.first+i  < 8)&&(space[v.first+i][v.second])) GIVE;
      if((v.first-i  >=0)&&(space[v.first-i][v.second])) GIVE;
      if((v.second+i < 8)&&(space[v.first][v.second+i])) GIVE;
      if((v.second-i >=0)&&(space[v.first][v.second-i])) GIVE;
      if((v.first+i < 8)&&(v.second+i < 8)&&(space[v.first+i][v.second+i])) GIVE;
      if((v.first+i < 8)&&(v.second-i >=0)&&(space[v.first+i][v.second-i])) GIVE;
      if((v.first-i >=0)&&(v.second+i < 8)&&(space[v.first-i][v.second+i])) GIVE;
      if((v.first-i >=0)&&(v.second-i >=0)&&(space[v.first-i][v.second-i])) GIVE;
    }
  }
  cout << "valid\n";
  return 0;
}


  //LL r[8], l[8], lr[15], rl[15];
  /*
    LL sum;
    for(LL i=0; i<8; i++) {
    sum = 0;
    
    for(LL j=0; j<8; j++) {
    if(space[i][j] == '*') {
    sum ++;
    
    }
    }
    if(sum > 1) cout << "invalid\n";
    
    }
    for(LL i=0; i<8; i++) {
    sum = 0;
    
    for(LL j=0; j<8; j++) {

    if(space[j][i] == '*') {

    sum ++;
    
    }

    }

    if(sum > 1) cout << "invalid\n";
    
    }
  return 0;
}
  */
