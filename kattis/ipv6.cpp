#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string input;
    cin >> input;
    int nM=0, n0;
    for(int i=0; i<int(input.length()); i++) {
        if(input[i]==':') 
            nM++;
    }
//    cout << nM << endl;
    n0 = 7 - nM + 1;
    if((input[0]==':')or(input[int(input.length())-1]==':'))
        n0 ++;
    if(input.length()==2)
        n0 ++;
//    cout << n0 << endl;
    for(int i=0; i<int(input.length()); i++) {
        if((input[i]==':') and (input[int(input.length())-1]!=':')) {
            if(i==0)
                continue;
            for(int k=0; k<n0; k++)
                cout << "0000:";
//            if(i!=int(input.length())-2)
//                i++;
            continue;
        }
        else if(input[i]==':') {
            for(int k=1; k<n0; k++) 
                cout << "0000:";
            cout << "0000";
            break;
        }
//        cout << "test 1" << endl;
        string tmp="";
        int j=i;
        for(; (input[j]!=':' and j<int(input.length())) ; j++) {
            tmp.append(1,input[j]);
        }
//        cout << "test 2" << endl;
        for(int k=int(tmp.length()); k<4; k++) {
            cout << '0';
        }
        i += int(tmp.length());
//        cout << endl << i << endl;
        if(i==int(input.length()))
            cout << tmp;
        else
            cout << tmp << ":";
    }
    cout << endl;
    return 0;
}
