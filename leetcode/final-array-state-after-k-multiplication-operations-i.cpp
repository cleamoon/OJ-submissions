class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto comp = [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            if (p1.first == p2.first) return p1.second > p2.second;
            return p1.first > p2.first;
        };
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>, 
            decltype(comp)
        > minpq{comp};
        for (auto i = 0; i < nums.size(); i++) {
            minpq.push(make_pair(nums[i], i));
        }
        for (auto i = 0; i < k; i++) {
            auto top = minpq.top();
            minpq.pop();
            minpq.push(make_pair(top.first * multiplier, top.second));
        }
        vector<int> res(nums.size());
        while(!minpq.empty()) {
            auto top = minpq.top();
            minpq.pop();
            res[top.second] = top.first;
        }
        return res;
    }
};