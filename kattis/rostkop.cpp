#include <iostream>
#define ULL unsigned long long 
using namespace std;

ULL n; 
ULL *a;

void sort(ULL * a, ULL n) {
    for(ULL i=1; i<n; i++) {
        for(ULL j=i+1; j<n; j++) {
            if(a[i]>a[j]) {
                ULL tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

int main(void) {
    cin >> n;
    a = new ULL [n];
    ULL me;
    for(ULL i=0; i<n; i++) 
        cin >> a[i];
    if(n==1) {
        cout << "0" << endl;
        return 0;
    }
    for(ULL i=0, me = a[0]; ; i++) {
        sort(a, n);
        if(me > a[n-1]) {
            cout << i << endl;
            return 0;
        }
        else {
            me ++; 
            a[n-1] --;
        }
    }
    return 0;
}
