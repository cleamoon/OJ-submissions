#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector <int> l;
    int a;
    for(int i=0; i<3; i++) {
        cin >> a;
        l.push_back(a);
    }
    sort(l.begin(), l.end());
    if(l[1]-l[0] > l[2]-l[1]) cout << l[1]-l[0]-1 << endl;
    else cout << l[2]-l[1]-1 << endl;
    return 0;
}
