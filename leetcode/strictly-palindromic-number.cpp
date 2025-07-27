class Solution {
vector<int> toBase(int n, int b) {
    vector<int> res;
    while(n != 0) {
        res.push_back(n % b);
        n /= b;
    }
    return res;
}

bool isPalindro(const vector<int> n) {
    int l = n.size() / 2;
    for (int i = 0; i < l; i++) {
        if (n[i] != n[n.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            if (!isPalindro(toBase(n, i))) return false;
        }
        return true;
    }
};