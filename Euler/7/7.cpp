#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    
    unsigned long lim = 10000000;
    bool* num;
    num = (bool*) malloc(lim * sizeof(bool));
    memset(num, true, lim);
    
    for (int i = 4; i < lim; i += 2) {
        num[i] = false;
    }
    for (int i = 3; i < sqrt(lim); i += 2) {
        for (int j = i * i; j < lim; j += 2*i) {
            num[j] = false;
        }
    }
    
    vector<unsigned long> prime = {2};
    for (unsigned long i = 3; i < lim; i += 2) {
        if (num[i])
            prime.push_back(i);
    }
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << prime[n-1] << endl;
    }
    return 0;
}