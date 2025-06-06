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
    
    vector<int> num (3001, -1);
    
    for (int a = 1; a <= 1000; a++) {
        for (int b = a; b <= 1500; b++) {
            for (int c = b; c <= 3000; c++) {
                if (a + b < c) break;
                if (a + b + c > 3000) break;
                if (a * a + b * b == c * c) {
                    if (num[a + b + c] < a * b * c)
                        num[a + b + c] = a * b * c;
                }
            }
        }
    }
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << num[n] << endl;
    }
    return 0;
}