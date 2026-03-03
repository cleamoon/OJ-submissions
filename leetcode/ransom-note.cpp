class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            vector<int> l1(26, 0);
            vector<int> l2(26, 0);
            for(auto i = 0; i < ransomNote.size(); i++) {
                l1[ransomNote[i] - 'a'] ++;
            }
            for(auto i = 0; i < magazine.size(); i++) {
                l2[magazine[i] - 'a'] ++;
            }
            for (auto i = 0; i < 26; i++) {
                if (l1[i] > l2[i]) return false;
            }
            return true;
        }
    };