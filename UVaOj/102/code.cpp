#include <iostream>
#include <vector> 

using namespace std;

vector<int> input;

string ans;
int maxima = -1;

void calc(string str, int* pivot) {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        if (pivot[i] == 1) sum += input[i];
    }
    if (sum > maxima) {
        maxima = sum;
        ans = str;
    }
}

int main(void) {
    int n;
    int sum = 0;
    while(cin >> n) {
        sum += n;
        input.push_back(n);
        for(int i = 0; i < 8; i++) {
            cin >> n;
            sum += n;
            input.push_back(n);
        }
        int s1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        int s2[9] = {1, 0, 0, 0, 0, 1, 0, 1, 0};
        int s3[9] = {0, 1, 0, 1, 0, 0, 0, 0, 1};
        int s4[9] = {0, 1, 0, 0, 0, 1, 1, 0, 0};
        int s5[9] = {0, 0, 1, 1, 0, 0, 0, 1, 0};
        int s6[9] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
        
        calc("BCG", s2);
        calc("BGC", s1);
        calc("CBG", s5);
        calc("CGB", s6);
        calc("GBC", s3);
        calc("GCB", s4);
        cout << ans << ' ' << sum - maxima << endl;
        input.clear();
        sum = 0;
        maxima = -1;
    }
    return 0;
}