class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sm;
        int np = 0;
        vector<int> bg;
        for (auto n : nums) {
            if (n < pivot) sm.push_back(n);
            else if (n > pivot) bg.push_back(n);
            else np++;
        }
        for (auto i = 0; i < sm.size(); i++) {
            nums[i] = sm[i];
        }
        for (auto i = 0; i < np; i++) {
            nums[i + sm.size()] = pivot;
        }
        for (auto i = 0; i < bg.size(); i++) {
            nums[i + sm.size() + np] = bg[i];
        }
        return nums;
    }
};