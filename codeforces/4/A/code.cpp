#include <iostream>
using namespace std;

int main(void) {
    int i;
    cin >> i;
    if ( i < 3 || i % 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}