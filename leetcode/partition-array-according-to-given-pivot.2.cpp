class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        int i = 0;

        for (auto n : nums) {
            if (n < pivot) {
                res[i] = n;
                i++;
            }
        }
        for (auto n : nums) {
            if (n == pivot) {
                res[i] = n;
                i++;
            }
        }
        for (auto n : nums) {
            if (n > pivot) {
                res[i] = n;
                i++;
            }
        }
        return res;
    }
};