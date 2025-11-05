class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto cmp = [](pair<int, unsigned> l, pair<int, unsigned> r) { return l.first < r.first; };
        std::priority_queue<pair<int, unsigned>, std::vector<pair<int, unsigned>>, decltype(cmp)> pq;
        for(auto i = 0; i < score.size(); i++) {
            pq.push(make_pair(score[i], i));
        }
        std::vector<string> ans(score.size());
        auto const first = pq.top();
        pq.pop();
        ans[first.second] = "Gold Medal";
        if (pq.empty()) {
            return ans;
        }
        auto const second = pq.top();
        pq.pop();
        ans[second.second] = "Silver Medal";
        if (pq.empty()) {
            return ans;
        }
        auto const third = pq.top();
        pq.pop();
        ans[third.second] = "Bronze Medal";
        if (pq.empty()) {
            return ans;
        }
        unsigned u = 4;
        while(!pq.empty()) {
            auto const el = pq.top();
            pq.pop();
            ans[el.second] = std::to_string(u);
            u += 1;
        }
        return ans;
    }
};