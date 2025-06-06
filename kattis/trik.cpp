#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a=1, b=0, c=0;
    string in;
    cin >> in;
    for(int i=0; i<in.length(); i++) {
        if(in[i]=='A') swap(a,b);
        else if(in[i]=='B') swap(b,c);
        else swap(a,c);
    }
    if(a) cout << 1 << endl;
    else if(b) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}
