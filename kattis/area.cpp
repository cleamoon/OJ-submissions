#include <iostream>
using namespace std;
int main() {
    unsigned int n, m, sum=0;
    cin >> n >> m;

    unsigned int** a = new unsigned int*[m];
    for(unsigned int i = 0; i < m; ++i)
        a[i] = new unsigned int[n];

    for(unsigned int i=0; i<n; i++)
        for(unsigned int j=0; j<m; j++) {
            cin >> a[j][i];
            if(a[j][i]) {
                sum += 2;
                sum += 4*a[j][i];
            }
        }
    for(unsigned int i=0; i<n; i++)
        for(unsigned int j=0; j<m-1; j++) {
            if(a[j][i]<a[j+1][i])
                sum -= 2*a[j][i];
            else 
                sum -= 2*a[j+1][i];
//            sum -= 2*MIN(a[j][i], a[j+1][i]);
        }
    for(unsigned int i=0; i<m; i++)
        for(unsigned int j=0; j<n-1; j++) {
            
            if(a[i][j]<a[i][j+1])
                sum -= 2*a[i][j];
            else
                sum -= 2*a[i][j+1];
//            sum -= 2*MIN(a[i][j], a[i][j+1]);
        }
    cout << sum << endl;
    return 0;
}
