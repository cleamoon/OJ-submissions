class Solution {
private:
unordered_map<int, int> res;

public:
    void calc(vector<int>& nums, int pos = 0, int value = 0) {
        if (pos == nums.size()) {
            auto it = res.find(value);
            if (it != res.end()) {
                it->second ++;
            } else {
                res.insert(make_pair(value, 1));
            }
            return;
        }
        calc(nums, pos + 1, value);
        calc(nums, pos + 1, value | nums[pos]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        calc(nums);
        int max = -1;
        for(auto it = res.begin(); it != res.end(); it++) {
            max = max > it->second ? max : it->second;
        }
        return max;
    }
};