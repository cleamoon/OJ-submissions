#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    long long n, sum=0;
    cin >> n;
    long long a[n+1];
    for(long long i=0; i<n+1; i++)
        cin >> a[i];
//    long long s[n];
    for(long long i=0; i<n; i++) {
//        cout << 2*((long long)abs(a[i+1]-a[i]+5)) << endl;
        sum += (2*((long long)abs(a[i+1]-a[i]+5))+60);
    }
    cout << sum << endl;
    return 0;
}
