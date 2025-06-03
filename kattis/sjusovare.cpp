#include <iostream>
#define ULL long long
using namespace std;
int main(void) {
    ULL n;
    cin >> n;
    for(ULL i=1; i<=n; i++) {
        ULL h, m, t, gon;
        cin >> h >> m >> t >> gon;
        if(h>=7) {
            cout << i;
            if(i!=n) 
                cout << " ";
            else
                cout << endl;
        }
        else if((h+(t*gon+m)/60)>=7) {
            cout << i;
            if(i!=n)
                cout << " ";
            else
                cout << endl;
        }
        else 
            continue;
    }
    return 0;
}
