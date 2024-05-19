#include <iostream>
using namespace std;
int main(void) {
    int a[9], sum=0;
    for(int i=0; i<9; i++) {
        cin >> a[i];
    }
    for(int i=1; i<10; i+=2) {
        sum += 3*a[i-1];
        sum %= 10;
    }
    for(int i=2; i<9; i+=2) {
        sum += 7*a[i-1];
        sum %= 10;
    }
    cout << sum << endl;
    return 0;
}
