#include <iostream>
#define ULL unsigned long long
using namespace std;
int main() {
    ULL k;
    cin >> k;
    if(k%100)
        k += 100-k%100;
    ULL n=0;
//    cout << "n" << n << endl;
//    cout << "k" << k << endl;
    n += (k-k%500)/500;
    k %= 500;
    if(!k) {
        cout << n << endl;
        return 0;
    }
//    cout << "n" << n << endl;
//    cout << "k" << k << endl;
    n += (k-k%200)/200;
    k %= 200;
    if(!k) {
        cout << n << endl;
        return 0;
    }
//    cout << "n" << n << endl;
//    cout << "k" << k << endl;
    n += (k-k%100)/100;
    k %= 100;
    if(!k) {
        cout << n << endl;
        return 0;
    }
    return 0;
}
