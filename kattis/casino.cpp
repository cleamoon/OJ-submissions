#include <iostream>
using namespace std;
int main() {
    double n, k, p;
    cin >> n >> k >> p;
    if (n*p < k) 
        cout << "Spela" << endl;
    else
        cout << "Spela inte!" << endl;
    return 0;
}
