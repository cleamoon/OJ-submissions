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

typedef unsigned long ul;

int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        ul tn;
        cin >> tn;
        ul n = tn;

        for (ul i = 2; i < sqrt(n) + 1; i ++) {
            if (n % i == 0) {
                n /= i;
                i --;
            }
        }
        cout << n << endl;
    }
    return 0;
}
