#include <vector>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream key ("keylog.txt");
    vector<set<int>> prev(10, set<int>{});
    vector<bool> used(10, true);

    if (key.is_open()) {
        string str;
        while (getline(key, str)) {
            cout << str << endl;
            prev[str[1]-'0'].insert(str[0]-'0');
            prev[str[2]-'0'].insert(str[1]-'0');
            used[str[0]-'0'] = false;
            used[str[1]-'0'] = false;
            used[str[2]-'0'] = false;
        }
        key.close();
    }

    while(true) {
        bool isDone = true;
        for (auto s : prev) {
            if (!s.empty()) {
                isDone = false;
                break;
            }
        }
        if (isDone) {
            for (int i = 0; i < 10; i++) 
                if (!used[i]) 
                    cout << i;
            break;
        }

        int min = 10;
        for (int i = 0; i < 10; i++) {
            if (!used[i] && prev[i].empty() && min > i) 
                min = i;
        }
        cout << min;
        used[min] = true;
        for (auto it = prev.begin(); it != prev.end(); it++) {
            it->erase(min);
        }
    }
    cout << endl;
    return 0;
}
