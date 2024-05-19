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
    
    int lim = 1000001;
    
    vector<bool> prime (lim, true); 
    
    prime[1] = false;
    
    for (int i = 4; i < lim; i += 2) {
        prime[i] = false;
    }
    
    for (int i = 3; i < sqrt(lim); i += 2) {
        for (int j = i * i; j < lim; j += 2*i) {
            prime[j] = false;
        }
    }

    unsigned long sum = 0;
    
    vector<unsigned long> num (lim, 0);
    
    for (unsigned long i = 1; i < lim; i++) {
        if (prime[i]) sum += i;
        num[i] = sum;
    }

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << num[n] << endl;
    }
    return 0;
}
