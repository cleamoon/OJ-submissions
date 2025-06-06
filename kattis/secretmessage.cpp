#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

ULL lesq(ULL l) {
  for(ULL i=1;; i++) {
    if(i*i >= l) return i;
  }
}

int main(void) {
  string in;
  ULL n, m;
  cin >> n;
  for(ULL i=0; i<n; i++) {
    cin >> in;
    ULL l = in.length();
    m = lesq(l);
    char** out;
    out = (char**) malloc (m*sizeof(char*));
    for(ULL j=0; j<m; j++) {
      out[j] = (char*) malloc (m*sizeof(char));
    }
    //cout << in << " " << m << endl;
    for(ULL j=0; j<m; j++) {
      for(ULL k=0; k<m; k++) {
	ULL tt = j*m+k;
	if(tt <= l)
	  out[j][k] = in[j*m+k];
	else
	  out[j][k] = '*';
      }
    }
    for(ULL j=0; j<m; j++) {
      for(ULL k=0; k<m; k++) {
	if(isalpha(out[m-k-1][j]))
	  printf("%c", out[m-k-1][j]);
      }
    }
    //cout << endl;
    printf("\n");
  }
  return 0;
}
