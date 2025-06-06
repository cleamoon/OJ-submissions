#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    string a,b;
    cin >> a >> b;
    int l = a.length();
    cout << a << endl << b << endl;
    for(int j=0; j<l; j++) {
      if(a[j]==b[j]) printf(".");
      else printf("*");
    }
    printf("\n\n");
  }
  return 0;
}
