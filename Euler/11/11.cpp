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

typedef unsigned long long ull;

int main(){
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++){
    	for(int grid_j = 0;grid_j < 20;grid_j++){
    		cin >> grid[grid_i][grid_j];
    	}
    }
    
    ull maxp = 0;
    
    for(int i = 0; i < 20 - 3; i++) {
        for (int j = 0; j < 20; j++) {
            ull cpi = 1;
            ull cpj = 1;
            for (int k = 0; k < 4; k++) {
                cpi *= grid[i + k][j];
                cpj *= grid[j][i + k];
            }
            if (cpi > maxp) {
                maxp = cpi;
            }
            if (cpj > maxp) {
                maxp = cpj;
            }
        }
    }
    
    for(int i = 0; i < 20 - 3; i++) {
        for (int j = 0; j < 20 - 3; j++) {
            ull cp = 1;
            for (int k = 0; k < 4; k++) {
                cp *= grid[i + k][j + k];
            }
            if (cp > maxp) {
                maxp = cp;
            }
        }
    }
    
    for(int i = 0; i < 20-4; i++) {
        for (int j = 3; j < 20; j++) {
            ull cpi = 1;
            for (int k = 0; k < 4; k++) {
                cpi *= grid[i + k][j - k];
            }
            if (cpi > maxp) {
                maxp = cpi;
            }
        }
    }
    
    cout << maxp << endl;
    
    return 0;
}