#include <iostream>
//#define ULL unsigned long long 
using namespace std;
int main(void) {
    int use;
    int n, antal=0;
    cin >> n;
    if(n==1) {
        cout << "1" << endl;
        return 0;
    }
    int a[n];
    for(int i=0; i<n; i++)
        a[i] = 1;
/*    for(int i=2; i<n; i+=3) {
            a[i]=0;
    }*/
/*    for(int i=0; i<50; i++) {
        if(a[i])
            cout << 2*i+1 << endl;
    }*/
    a[0]=2;
//    a[1]=2;
    while(1) {
        for(int i=0; i<n; i++) {
            if((a[i]==1)and(a[i]!=2)) {
                use = 2*i+1;
                a[i]=2;
                break;
            }
        }
        for(int i=0, j=0; i<n; i++) {
            if(a[i])
                j++;
            if(j==use) {
                a[i]=0;
                j=0;
            }
        }
//        cout << use << endl;
        if(use>n)
            break;
    }
/*    for(int i=0; i<n; i++) {
        if(a[i])
            cout << 2*i+1 << endl;
    }*/
    for(int i=0; i*2+1<=n; i++) {
        if(a[i])
            antal++;
    }
    cout << antal << endl;
    return 0;
}
