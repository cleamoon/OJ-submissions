class Solution {
  public:
      vector<int> transformArray(vector<int>& nums) {
          unsigned e = 0;
          for(auto i : nums) {
              if (i % 2 == 0) e++;
          }
          vector<int> res(nums.size(), 0);
          for(auto i = 0; i + e < nums.size(); i++) {
              res[i + e] = 1;
          }
          return res;
      }
  };