class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int curr = k;
        vector<int> res;
        int i = num.size() - 1;
        int ext = 0;
        while (curr != 0 || i >= 0 || ext != 0) {
            int d = curr % 10;
            int sum = 0;
            if (i < 0) {
                sum = d + ext;
            } else {
                sum = d + num[i] + ext;
            }
            if (sum >= 10) {
                ext = 1;
                sum %= 10;
            } else {
                ext = 0;
            }
            cout << sum << endl;
            res.push_back(sum);
            i --;
            curr /= 10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};