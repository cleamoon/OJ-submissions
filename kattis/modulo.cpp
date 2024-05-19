#include <bits/stdc++.h>
using namespace std;

int main(void) {
    //vector <unsigned> a;
    unsigned t;
    set <unsigned> ans;
    for(int i=0; i<10; i++) {
        cin >> t;
        ans.insert(t%42);
    }
    cout << ans.size() << endl;
    return 0;
}
