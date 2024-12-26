#include <bits/stdc++.h>
using namespace std;

int main(void) {
    map <int, int> a, b;
    map <int, int>::iterator it;
    int m, n;
    for(int i=0; i<3; i++) {
        cin >> m >> n;
        it = a.find(m);
        if(it != a.end()) it->second++;
        else a.insert(make_pair(m, 0));
        it = b.find(n);
        if(it != b.end()) it->second++;
        else b.insert(make_pair(n, 0));
    }
    for(it = a.begin(); it != a.end(); it++) {
        if(!(it->second)) {
            cout << it->first << " ";
            break;
        }
    }
    for(it = b.begin(); it != b.end(); it++) {
        if(!(it->second)) {
            cout << it->first << endl;
            break;
        }
    }
    return 0;
}
