#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double c, r;
    cin >> c >> r;
    printf("%.8lF\n", 100*(c-r)*(c-r)/c/c);
    return 0;
}
